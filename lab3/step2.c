/**
 * Name: Dan Sedano
 * Date: 2020-03-22
 * Title: Lab 3 Step 2
 * Description: This program shows how pipes work.
 * This program reads each individual argument in the upsream then passes the arguments
 * to the downstream where it is processed.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>

//main

int main(int argc, char *argv[]) {
	int fds[2];
	char buff[60];
	int count;
	int i;
	pipe(fds);

	if (fork() == 0) {
		printf("Writer on the upstream end of the pipe -> %d arguments \n", argc);
		close(fds[0]);
		// writes each argument to the upstream individually
		for (i = 0; i < argc; i++) {
			write(fds[1],argv[i],strlen(argv[i]));
		}
		exit(0);
	}
	else if (fork() == 0) {
		printf("\nReader on the downstream end of the pipe \n");
		close(fds[1]);
		//reads on the downstream and each character individually
		while((count = read(fds[0],buff,60)) > 0) {
			for(i = 0; i < count; i++) {
				write(1,buff + i,1);
				write(1," ",1);
			}
			printf("\n");
		}
		exit(0);
	}
	else {
		//closes all upstream and downstream
		close(fds[0]);
		close(fds[1]);
		// waits for children to finish
		wait(0);
		wait(0);
	}
	return 0;
}
