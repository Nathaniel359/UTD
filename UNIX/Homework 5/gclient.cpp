#include "LineInfo.h"
#include <algorithm>
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

using namespace std;

/*
Program Name: gclient
Date: 2023-04-17
Author: Nathaniel Tan
Module Purpose
This program will play a word guessing game.
The client will guess letters that are sent to the server.
The client gets 12 letter guesses per word.
*/

// global constants
int const FAILURE = -1;
int const MAX_PIPE_MESSAGE_SIZE = 100;
int const CHILD_PID = 0;

int fd;
int fd_client;
int fd_server;
char knownPipe[] = "./knownPipe";
char clientPipe[] = "./clientPipe";
char serverPipe[MAX_PIPE_MESSAGE_SIZE] = {0};

int main() {
  if (mkfifo(clientPipe, 0666) == -1) {
    cerr << "Error creating named pipe: " << strerror(errno) << endl;
    exit(EXIT_FAILURE);
  }

  fd = open(knownPipe, O_WRONLY);

  try {
    if (write(fd, clientPipe, sizeof(clientPipe)) == FAILURE)
      throw domain_error(LineInfo("Error writing to pipe", __FILE__, __LINE__));
  } catch (exception &e) {
    cout << e.what() << endl;
    cout << "\nPress the enter key once or twice to leave...\n";
    cin.ignore();
    cin.get();
    exit(EXIT_FAILURE);
  }

  fd_client = open(clientPipe, O_RDONLY);
  try {
    if (fd_client == FAILURE)
      throw domain_error(LineInfo("Error opening pipe", __FILE__, __LINE__));
  } catch (exception &e) {
    cout << e.what() << endl;
    cout << "\nPress the enter key once or twice to leave...\n";
    cin.ignore();
    cin.get();
    exit(EXIT_FAILURE);
  }

  // reads server writes to child pipe to get the client try number message
  char clientTryNumber[MAX_PIPE_MESSAGE_SIZE] = {0};
  try {
    if (read(fd_client, clientTryNumber, sizeof(clientTryNumber)) == FAILURE)
      throw domain_error(
          LineInfo("Error reading from pipe", __FILE__, __LINE__));
  } catch (exception &e) {
    cout << e.what() << endl;
    cout << "\nPress the enter key once or twice to leave...\n";
    cin.ignore();
    cin.get();
    exit(EXIT_FAILURE);
  }
  // again for the random word message
  char randWord[MAX_PIPE_MESSAGE_SIZE] = {0};
  try {
    if (read(fd_client, randWord, sizeof(randWord)) == FAILURE)
      throw domain_error(
          LineInfo("Error reading from pipe", __FILE__, __LINE__));
  } catch (exception &e) {
    cout << e.what() << endl;
    cout << "\nPress the enter key once or twice to leave...\n";
    cin.ignore();
    cin.get();
    exit(EXIT_FAILURE);
  }
  // again for the server read from client write message
  try {
    if (read(fd_client, serverPipe, sizeof(serverPipe)) == FAILURE)
      throw domain_error(
          LineInfo("Error reading from pipe", __FILE__, __LINE__));
  } catch (exception &e) {
    cout << e.what() << endl;
    cout << "\nPress the enter key once or twice to leave...\n";
    cin.ignore();
    cin.get();
    exit(EXIT_FAILURE);
  }

  fd_server = open(serverPipe, O_WRONLY);
  try {
    if (fd_server == FAILURE)
      throw domain_error(LineInfo("Error opening pipe", __FILE__, __LINE__));
  } catch (exception &e) {
    cout << e.what() << endl;
    cout << "\nPress the enter key once or twice to leave...\n";
    cin.ignore();
    cin.get();
    exit(EXIT_FAILURE);
  }

  int tryNumber = (int)clientTryNumber[0];
  tryNumber = 0;

  cout << "Game Start" << endl << "You have 12 letter guesses to win" << endl;

  while (tryNumber < 13) {
    char guessWord[MAX_PIPE_MESSAGE_SIZE] = {0};
    try {
      if (read(fd_client, guessWord, sizeof(guessWord)) == FAILURE)
        throw domain_error(
            LineInfo("Error reading from pipe", __FILE__, __LINE__));
    } catch (exception &e) {
      cout << e.what() << endl;
      cout << "\nPress the enter key once or twice to leave...\n";
      cin.ignore();
      cin.get();
      exit(EXIT_FAILURE);
    }
    if (strcmp(guessWord, randWord) == 0) {
      cout << endl << guessWord << endl << endl << "You Win!" << endl;
      break;
    } else if (tryNumber >= 12) {
      cout << "Out of tries : 12 allowed" << endl
           << "The word is: " << randWord << endl
           << endl;
      break;
    }
    cout << endl
         << "Client: 1" << endl
         << "No of tries: " << tryNumber << endl
         << "(Guess) Enter a letter in the word : " << guessWord << endl
         << endl;
    char guessLetter[1];
    cin >> guessLetter;
    try {
      if (write(fd_server, guessLetter, sizeof(guessLetter)) == FAILURE)
        throw domain_error(
            LineInfo("Error writing to pipe", __FILE__, __LINE__));
    } catch (exception &e) {
      cout << e.what() << endl;
      cout << "\nPress the enter key once or twice to leave...\n";
      cin.ignore();
      cin.get();
      exit(EXIT_FAILURE);
    }
    tryNumber++;
  }

  // closes and unlinks from all named pipes
  close(fd);
  unlink(knownPipe);
  close(fd_client);
  unlink(clientPipe);
  close(fd_server);
  unlink(serverPipe);
}
