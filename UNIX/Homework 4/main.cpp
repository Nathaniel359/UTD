#include "LineInfo.h"  
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

/*
Program Name: forkexecvp
Date: 2023-04-10
Author: Nathaniel Tan
Module Purpose
This program will create multiple processes
to perform various calculations on a random
assortment of integers.
*/

int const READ = 0;
int const WRITE = 1;
int const CHILD_PID = 0;
int const MAX_PIPE_MESSAGE_SIZE = 1000;

int main(int argc, char *argv[]) {
  string fileName = argv[1];
  int numNums = stoi(argv[2]);
  int range = stoi(argv[2]);
  // seed rng
  time_t t; 
  srand((unsigned)time(&t));

  
  ofstream file(fileName);
  if (file.is_open()) {
    for (int i = 0; i < numNums; i++) {
      file << rand() % range + 1 << endl;
    }
    file.close();
  }
  
  int cPipe[MAX_PIPE_MESSAGE_SIZE];
  string msgArr[] = {"sum", "average", "greatest", "least"};
  for (int i = 0; i < sizeof(msgArr) / 8; i++) {
    pipe(cPipe);
    int pid = fork();
    // parent process
    if (pid != CHILD_PID) {
      close(cPipe[READ]);
      write(cPipe[WRITE], msgArr[i].c_str(), sizeof(msgArr[i].c_str()));
      cout << "Parent pid: " << getpid() << " to Child Process No : " << i << endl << "Send Message : " << msgArr[i] << endl;
    }
    // child process
    else {
      close(cPipe[WRITE]);
      char receivedMessage[MAX_PIPE_MESSAGE_SIZE] = { 0 };
      read(cPipe[READ], receivedMessage, sizeof(receivedMessage));
      cout << "Child pid: " << getpid() << " Child Process No : " << i << " Received Message: " << receivedMessage << endl;
      char * arglist[] = { (char *)"./calculate", receivedMessage,
                           (char*)fileName.c_str(), NULL };
      cout << "Child pid : " << getpid() << " Child Process No : " << i << "\nexecvp(./calculate, ./calculate, randomnumber.txt, NULL)" << endl;
      
      string answerFileName = "answer";
      answerFileName += receivedMessage;
      answerFileName += ".txt";
      
      freopen(answerFileName.c_str(), "w", stdout);
      
      close(cPipe[READ]);
      
      try {
        if (execvp(arglist[0], arglist) < 0)
          throw domain_error(LineInfo("execvp failed", __FILE__, __LINE__));
      } 
      catch (exception &e) {
        cout << e.what() << endl;
        cout << "\nPress the enter key once or twice to leave...\n";
        cin.ignore();
        cin.get();
        exit(EXIT_FAILURE);
      }
    }  
  }
  cout << "Parent pid: " << getpid() << " Start - Wait for all calculate children to finish" << endl;
  // wait for children
  pid_t child_pid, wpid;
  int status = 0;
  
  for (int i = 0; i < 4; i++) {
    if ((child_pid = fork()) == 0)
      exit(0);
  }
  
  while ((wpid = wait(&status)) > 0);
  
  cout << "Parent pid: " << getpid() << " Done - Wait for all calculate children to finish" << endl;
  cout << endl << "Parent pid: " << getpid() << " Use execvp() cat to display answer files:" << endl;
  for (int i = 0; i < sizeof(msgArr) / 8; i++ ) {
    int pid = fork();
    // child
    if (pid == CHILD_PID) {
      string answerFileName = "answer";
      answerFileName += msgArr[i];
      answerFileName += ".txt";
      cout << "Child pid: " << getpid() << "\ncat " << answerFileName << endl;
      
      char* arglist[] = { (char*)"cat", (char*)answerFileName.c_str(), NULL };
      
      try {
        if (execvp(arglist[0], arglist) < 0)
          throw domain_error(LineInfo("execvp failed", __FILE__, __LINE__));
      } 
      catch (exception &e) {
        cout << e.what() << endl;
        cout << "\nPress the enter key once or twice to leave...\n";
        cin.ignore();
        cin.get();
        exit(EXIT_FAILURE);
      }
    }
  }
  cout << "Parent pid : " << getpid() << " Start - Wait for all display answer file children to finish" << endl;
  // wait for children
  status = 0;
  
  for (int i = 0; i < 4; i++) {
    if ((child_pid = fork()) == 0)
      exit(0);
  }
  
  while ((wpid = wait(&status)) > 0);
  cout << "Parent pid : " << getpid() << " Done - Wait for all display answer file children to finish" << endl;
}
