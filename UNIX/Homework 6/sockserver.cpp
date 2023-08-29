#include "LineInfo.h"
#include <arpa/inet.h>
#include <fstream>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

/*
Program Name: sockserver
Date: 2023-04-26
Author: Nathaniel Tan
Module Purpose
This program will play a number guessing game.
*/

int const FAILURE = -1;
int const MAX_PIPE_MESSAGE_SIZE = 1024;

int main() {
  // create a socket
  int serverfd = socket(AF_INET, SOCK_STREAM, 0);
  try {
    if (serverfd == FAILURE)
      throw domain_error(LineInfo("Error creating socket", __FILE__, __LINE__));
  } catch (exception &e) {
    cout << e.what() << endl;
    cout << "\nPress the enter key once or twice to leave...\n";
    cin.ignore();
    cin.get();
    exit(EXIT_FAILURE);
  }

  // setup sockaddr_in
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8888);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // bind socket
  try {
    if (bind(serverfd, (struct sockaddr *)&addr, sizeof(addr)) == FAILURE)
      throw domain_error(LineInfo("Error binding socket", __FILE__, __LINE__));
  } catch (exception &e) {
    cout << e.what() << endl;
    cout << "\nPress the enter key once or twice to leave...\n";
    cin.ignore();
    cin.get();
    exit(EXIT_FAILURE);
  }

  // listen to socket
  try {
    if (listen(serverfd, 3) == FAILURE)
      throw domain_error(
          LineInfo("Error listening to socket", __FILE__, __LINE__));
  } catch (exception &e) {
    cout << e.what() << endl;
    cout << "\nPress the enter key once or twice to leave...\n";
    cin.ignore();
    cin.get();
    exit(EXIT_FAILURE);
  }

  // accept listen
  int clientfd;
  struct sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);
  clientfd = accept(serverfd, (struct sockaddr *)&client_addr, &client_len);
  try {
    if (clientfd == FAILURE)
      throw domain_error(
          LineInfo("Error accepting listen to socket", __FILE__, __LINE__));
  } catch (exception &e) {
    cout << e.what() << endl;
    cout << "\nPress the enter key once or twice to leave...\n";
    cin.ignore();
    cin.get();
    exit(EXIT_FAILURE);
  }

  // create random number and associated string
  time_t t;
  srand((unsigned)time(&t));
  int randNum = 1 + (rand() % 100);
  string randNumStr = to_string(randNum);

  char guessMessage[] = "Enter a number:\n";
  string result;
  int read_size;
  for (;;) {
    // read guess message
    char clientGuessMessage[MAX_PIPE_MESSAGE_SIZE] = {0};
    try {
      if ((read_size = read(clientfd, clientGuessMessage,
                           sizeof(clientGuessMessage))) == FAILURE)
        throw domain_error(
            LineInfo("Error reading from socket", __FILE__, __LINE__));
    } catch (exception &e) {
      cout << e.what() << endl;
      cout << "\nPress the enter key once or twice to leave...\n";
      cin.ignore();
      cin.get();
      exit(EXIT_FAILURE);
    }

    // check if request and write random number string
    if (strcmp(clientGuessMessage, guessMessage) == 0) {
      try {
        if (write(clientfd, randNumStr.c_str(), randNumStr.length()) == FAILURE)
          throw domain_error(
              LineInfo("Error writing to socket", __FILE__, __LINE__));
      } catch (exception &e) {
        cout << e.what() << endl;
        cout << "\nPress the enter key once or twice to leave...\n";
        cin.ignore();
        cin.get();
        exit(EXIT_FAILURE);
      }
    }

    else {
      if (read_size > 0) {  
        int guess = stoi(clientGuessMessage);
        string guessStr = to_string(guess);

        if (randNum == guess) {
          result = "You Win !!\n\nThe number is : " + guessStr;
        } else if (randNum > guess) {
          result = "The number is greater than : " + guessStr;
        } else if (randNum < guess) {
          result = "The number is less than : " + guessStr;
        }
        try {
          if (write(clientfd, result.c_str(), result.length()) == FAILURE)
            throw domain_error(
                LineInfo("Error writing to socket", __FILE__, __LINE__));
        } catch (exception &e) {
          cout << e.what() << endl;
          cout << "\nPress the enter key once or twice to leave...\n";
          cin.ignore();
          cin.get();
          exit(EXIT_FAILURE);
        }
      }

      else if (read_size == 0) {
        cout << "Client disconnected" << endl;
        fflush(stdout);
        break;
      }
    }
  }
}
