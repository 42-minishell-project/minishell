
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


void process2() {
	printf("child2: %d\n", getpid());
	usleep(3000000);
	
	printf("child2: %d exit\n", getpid());
}

void process1() {
	printf("child: %d\n", getpid());
	int pid = fork();
	if (pid == 0) {
		process2();
		exit(0);
	}
	usleep(5000000);
	printf("child: %d exit\n", getpid());
	// int wpid = wait(0);
	int wpid = waitpid(0, 0, 0);
	printf("child: %d - wait %d\n", getpid(), wpid);
}


int main() {
	printf("main process: %d\n", getpid());

	int pid = fork();
	if (pid == 0) {
		process1();
		exit(0);
	}
	// int wpid = wait(0);
	int wpid = waitpid(0, 0, 0);
	printf("main: %d - wait %d\n", getpid(), wpid);
}


