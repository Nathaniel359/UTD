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
Program Name: sockclient
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

  // connect to socket
  try {
    if (connect(serverfd, (struct sockaddr *)&addr, sizeof(addr)) == FAILURE) {
      throw domain_error(
          LineInfo("Error connecting to socket", __FILE__, __LINE__));
    }
  } catch (exception &e) {
    cout << e.what() << endl;
    cout << "\nPress the enter key once or twice to leave...\n";
    cin.ignore();
    cin.get();
    exit(EXIT_FAILURE);
  }

  // display start of game
  cout << endl << endl << "Try to guess a number between 1 and 100" << endl << endl;

  int tryNum = 1;
  int guessNum;
  string guessNumStr;
  string requestMessage = "Enter a number:\n";
  for (;;) {
    cout << "Current Try Number : " << tryNum << endl;
    cout << "Enter number guess : " << endl << endl;
    cin >> guessNum;
    guessNumStr = to_string(guessNum);

    try {
      if (write(serverfd, guessNumStr.c_str(), guessNumStr.length()) == FAILURE)
        throw domain_error(
            LineInfo("Error writing to socket", __FILE__, __LINE__));
    } catch (exception &e) {
      cout << e.what() << endl;
      cout << "\nPress the enter key once or twice to leave...\n";
      cin.ignore();
      cin.get();
      exit(EXIT_FAILURE);
    }

    char serverMessage[MAX_PIPE_MESSAGE_SIZE] = {0};
    try {
      if (read(serverfd, serverMessage, sizeof(serverMessage)) == FAILURE)
        throw domain_error(
            LineInfo("Error reading from socket", __FILE__, __LINE__));
    } catch (exception &e) {
      cout << e.what() << endl;
      cout << "\nPress the enter key once or twice to leave...\n";
      cin.ignore();
      cin.get();
      exit(EXIT_FAILURE);
    }

    cout << endl
         << "Server reply : " << endl
         << endl
         << serverMessage << endl
         << endl;

    string serverMessageStr = serverMessage;
    if (serverMessageStr.find("Win") != string::npos) {
      break;
    }

    tryNum++;
    if (tryNum > 12) {
      cout << "The maximum number of tries 12 is done." << endl;
      cout << "Send Random Number" << endl;

      try {
        if (write(serverfd, requestMessage.c_str(), requestMessage.length()) ==
            FAILURE)
          throw domain_error(
              LineInfo("Error writing to socket", __FILE__, __LINE__));
      } catch (exception &e) {
        cout << e.what() << endl;
        cout << "\nPress the enter key once or twice to leave...\n";
        cin.ignore();
        cin.get();
        exit(EXIT_FAILURE);
      }

      char randNum[MAX_PIPE_MESSAGE_SIZE] = {0};
      try {
        if (read(serverfd, randNum, sizeof(randNum)) == FAILURE)
          throw domain_error(
              LineInfo("Error reading from socket", __FILE__, __LINE__));
      } catch (exception &e) {
        cout << e.what() << endl;
        cout << "\nPress the enter key once or twice to leave...\n";
        cin.ignore();
        cin.get();
        exit(EXIT_FAILURE);
      }

      int randNumInt = randNum[0];
      cout << "The random number is : " << randNumInt << endl << endl;
      cout << "Game is over" << endl << endl;
      break;
    }
  }
}
