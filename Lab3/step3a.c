/**
 *  Name: Dan Sedano
 *  Date: 2020-03-22
 *  Title: Lab3 Step 1
 *  Description
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>

//main
int main() {
	int fds[2];
	pipe(fds);
	// child 1 duplicates upstream into stdout
	if (fork() == 0) {
		dup2(fds[0],0);
		close(fds[1]);
		write(fds[1],execlp("cat","cat","/etc/passwd",(char *)0),strlen(buff)+1);
		//execlp("more","more",(char *)0);

	}
	// child 2 duplicates upstream into stdout
	else if (fork() == 0) {
		dup2:(fds[1],1);
		close(fds[0]);
		execlp("ls","ls",(char *)0);
	}
	// parent closes both ends and waits for children
	else {
		close(fds[0]);
		close(fds[1]);
		wait(0);
		wait(0);
	}
	return 0;
}

