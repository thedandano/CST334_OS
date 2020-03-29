// # Name: Dan Sedano
// # Date: 2020-03-13
// # Title: Lab2 - Task
// # Description: This programs displays how to create a child process.

#include <stdio.h> //printf, stderr
#include <sys/types.h> // pid_t
#include <unistd.h> // fork
#include <stdlib.h> // atoi
#include <errno.h> //errno

int main (int argc, char *argv[]) {
  pid_t pid;
  int i, n = atoi(argv[1]); //n microseconds from keyboard input to cause delay

  printf("\n Before forking.\n");

  // Calls the fork system call to make a child clone process
  pid = fork();
  //if pid is less than 0 then it's an error
  if(pid == -1) {
    fprintf(stderr, "Can't fork, error %d\n", errno);
  }
  // if pid is anything greater than 0 then it's the parent
  if (pid) {
    //Parent process
    for(i = 0; i < 100; i++) {
      printf("\t\t\t Parent Process %d\n", i);
      usleep(n);
    }
  }
  // at this point pid must be zero and thus the child
  else {
    // Child Process
    for (i = 0; i < 100; i++) {
      printf("Child process %d\n", i);
      usleep(n);
    }
  }
  return 0;
}
