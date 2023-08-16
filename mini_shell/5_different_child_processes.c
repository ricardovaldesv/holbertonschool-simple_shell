#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int i;
	pid_t child_pid;
	pid_t current_pid;
	int status;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();

		if (child_pid == -1) 
		{
			perror("Error:");
			return (1);
		}
		else if (child_pid == 0)
		{
			printf("Child %d executing ls -l /tmp:\n", i + 1);
			char *args[] = {"ls", "-l", "/tmp", NULL};
			current_pid = getpid();
			printf("ID child is :  %u\n", current_pid);
			execve("/bin/ls", args, NULL);
			perror("Execve failed");
			return (1);
		}
		else 
		{
			wait(&status);
			current_pid = getpid();
			printf("ID Parent is :  %u\n", current_pid);
			printf("Child %d exited\n", i + 1);
		}
	}
	return (0);
}
