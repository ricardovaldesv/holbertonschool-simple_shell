#include "main.h"

/**
 * executeCommand - It is responsible for executing a
 *                  command on a Unix or Linux system.
 * @command: string of input
 */

void executeCommand(char *command)
{
	char *token;
	pid_t child_pid;
	int argIndex = 0;
	char *args[20];
	int status;
	char fullPath[20];

	args[0] = NULL;
	for (token = strtok(command, " "); token != NULL;
			token = strtok(NULL, " "))
	{
		args[argIndex] = token;
		argIndex++;
	}
	args[argIndex] = NULL;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error when creating a child process");
		free(command);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (args[0] && !strchr(args[0], '/'))
		{
			if (findExecutable(args[0], fullPath))
				args[0] = fullPath;
		}
		if (execve(args[0], args, environ) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
