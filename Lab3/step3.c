/**
 * Name: Dan Sedano
 * Date: 2020-03-22
 * Title: Lab 3 Step 2
 * Description: This program shows how a pipe works by passing a cat command to grep.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>

//main

int main(int argc, char *argv[]) {
	
	int fds[2];
	pipe(fds);
	
	//duplicates to the upstream of stdout
	if (fork() == 0) {
		//closes the downstream
		close(fds[0]);
		//duplicates to the upstream
		dup2(fds[1],1);
		// creates the cat process with the argument /etc/passwd
		execlp("cat","cat", "/etc/passwd", NULL);
		exit(0);
	}
	// duplicates the downstream of stdin
	else if (fork() == 0) {
		// closes the upstream
		close(fds[1]);
		//duplicates the downstream
		dup2(fds[0],0);
		//creates the grep process will will recieve input from upstream
		execlp("grep", "grep", "root", NULL);
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
