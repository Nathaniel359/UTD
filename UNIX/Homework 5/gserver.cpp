// gserver process
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
Program Name: gserver
Date: 2023-04-17
Author: Nathaniel Tan
Module Purpose
This program will play a word guessing game.
The server will provide a random guess word
and fill in any matches with the guess letter.
*/

int const FAILURE = -1;
int const MAX_PIPE_MESSAGE_SIZE = 100;
int const CHILD_PID = 0;

int clientTryCount = 0;
int fd;
int fd_client;
int fd_server;
char knownPipe[] = "./knownPipe";
char clientPipe[MAX_PIPE_MESSAGE_SIZE] = {0};
char serverPipe[] = "./serverPipe";

int main(int argc, char *argv[]) {
  // server reads into a vector<string> from a file name provided by the argv[1]
  vector<string> words;
  ifstream file(argv[1]);
  istream_iterator<string> iterator(file);
  if (file.is_open())
    copy(iterator, istream_iterator<string>(), back_inserter(words));
  file.close();

  // server creates, then opens for reading a known named pipe for reading
  // client requester message.
  if (mkfifo(knownPipe, 0666) == -1) {
    if (errno != EEXIST) {
      cerr << "Error creating named pipe: " << strerror(errno) << endl;
      exit(EXIT_FAILURE);
    }
  }
  fd = open(knownPipe, O_RDONLY);
  try {
    if (fd == FAILURE)
      throw domain_error(LineInfo("Error opening pipe", __FILE__, __LINE__));
  } catch (exception &e) {
    cout << e.what() << endl;
    cout << "\nPress the enter key once or twice to leave...\n";
    cin.ignore();
    cin.get();
    exit(EXIT_FAILURE);
  }

  // server reads in on the known pipe name a client message.
  try {
    if (read(fd, clientPipe, sizeof(clientPipe)) == FAILURE)
      throw domain_error(
          LineInfo("Error reading from pipe", __FILE__, __LINE__));
  } catch (exception &e) {
    cout << e.what() << endl;
    cout << "\nPress the enter key once or twice to leave...\n";
    cin.ignore();
    cin.get();
    exit(EXIT_FAILURE);
  }

  // server is done with the requester known named pipe, so this named pipe is
  // closed and unlinked.
  close(fd);
  unlink(knownPipe);

  // server creates, then opens for writing the previously sent client created
  // unique named pipe.
  fd_client = open(clientPipe, O_WRONLY);
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

  // server creates a random word from the vector.
  //  seed rng
  time_t t;
  srand((unsigned)time(&t));
  string randWord = words[rand() % words.size()];

  // server creates a corresponding guess word made up of empty slots using
  // dashes (-) to represent the empty letter slots.
  string blankGuessWord = "";
  for (int i = 0; i < randWord.length(); i++) {
    blankGuessWord += "-";
  }

  // server increments the client try count.
  clientTryCount++;

  // server forks()
  int pid = fork();

  // CHILD PROCESS
  if (pid == CHILD_PID) {
    // create string of client try count, then writes it to client
    string clientTryCountStr = to_string(clientTryCount);
    try {
      if (write(fd_client, clientTryCountStr.c_str(),
                clientTryCountStr.length()) == FAILURE)
        throw domain_error(
            LineInfo("Error writing to pipe", __FILE__, __LINE__));
    } catch (exception &e) {
      cout << e.what() << endl;
      cout << "\nPress the enter key once or twice to leave...\n";
      cin.ignore();
      cin.get();
      exit(EXIT_FAILURE);
    }
    // sleeps for 2 seconds
    sleep(2);
    // writes out random word string to client
    try {
      if (write(fd_client, randWord.c_str(), randWord.length()) == FAILURE)
        throw domain_error(
            LineInfo("Error writing to pipe", __FILE__, __LINE__));
    } catch (exception &e) {
      cout << e.what() << endl;
      cout << "\nPress the enter key once or twice to leave...\n";
      cin.ignore();
      cin.get();
      exit(EXIT_FAILURE);
    }
    // creates pipe for child server reads of client writes
    if (mkfifo(serverPipe, 0666) == -1) {
      if (errno != EEXIST) {
        cerr << "Error creating named pipe: " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
      }
    }
    // writes pipe name out to client
    try {
      if (write(fd_client, serverPipe, sizeof(serverPipe)) == FAILURE)
        throw domain_error(
            LineInfo("Error writing to pipe", __FILE__, __LINE__));
    } catch (exception &e) {
      cout << e.what() << endl;
      cout << "\nPress the enter key once or twice to leave...\n";
      cin.ignore();
      cin.get();
      exit(EXIT_FAILURE);
    }
    // creates then opens child pipe for reading
    fd_server = open(serverPipe, O_RDONLY);
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
    /* loop
    writes guess word (with blanks) to client
    reads guess letter from client
    fills slots in guess word with any letter matches
    */
    while (clientTryCount < 12) {
      try {
        if (write(fd_client, blankGuessWord.c_str(), blankGuessWord.length()) ==
            FAILURE)
          throw domain_error(
              LineInfo("Error writing to pipe", __FILE__, __LINE__));
      } catch (exception &e) {
        cout << e.what() << endl;
        cout << "\nPress the enter key once or twice to leave...\n";
        cin.ignore();
        cin.get();
        exit(EXIT_FAILURE);
      }
      char clientGuessLetter[MAX_PIPE_MESSAGE_SIZE] = {0};
      try {
        if (read(fd_server, clientGuessLetter, sizeof(clientGuessLetter)) ==
            FAILURE)
          throw domain_error(
              LineInfo("Error reading from pipe", __FILE__, __LINE__));
      } catch (exception &e) {
        cout << e.what() << endl;
        cout << "\nPress the enter key once or twice to leave...\n";
        cin.ignore();
        cin.get();
        exit(EXIT_FAILURE);
      }
      for (int i = 0; i < randWord.length(); i++) {
        if (randWord[i] == clientGuessLetter[0]) {
          blankGuessWord[i] = clientGuessLetter[0];
        }
      }
    }
  }
  close(fd_client);
  unlink(clientPipe);
  close(fd_server);
  unlink(serverPipe);
}
