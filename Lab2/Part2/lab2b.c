// # Name: Dan Sedano
// # Date: 2020-03-13
// # Title: Lab2 - Task
// # Description: This programs displays how a child process an create a new process.

#include <stdio.h> //printf, stderr
#include <sys/types.h> // pid_t
#include <sys/wait.h> // wait
#include <unistd.h> // fork
#include <stdlib.h> // atoi
#include <errno.h> //errno

int main (int argc, char *argv[]) {
  pid_t pid;
  int i, n = atoi(argv[1]); //n microseconds from keyboard input to cause delay

  printf("\n Before forking.\n");
  // Calls the fork system call to make a clone child process
  pid = fork();

  //if pid is less than zero then it's an error
  if(pid == -1) {
    fprintf(stderr, "Can't fork, error %d\n", errno);
  }

  // When pid = 0 then it's the child
  if (pid == 0) {
    //Child Process
    // uses the execlp system call to create a new different process
    execlp("/bin/ls","ls",NULL);
  }
  // When pid is anything greater than zero it must be the parent
  else {
    // Parent Process
    // The wait function causes the parent to wait until the child is finished before continuing.
    wait(NULL); 
    printf("Child Complete\n");
    exit(0);
  }
  return 0;
}
