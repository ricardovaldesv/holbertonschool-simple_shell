#include "executeCommand.h"

/**
 * executeCommand - It is responsible for executing a
 *                  command on a Unix or Linux system.
 * @command: string of input
 */
int executeCommand(char *command)
{
	const char *delimiter = " ";
	char *token;
	pid_t child_pid;
	int argIndex = 0;
	char *args[20];
	int status;
	args[0] = NULL;

	for (token = strtok(command, delimiter); token != NULL; token = strtok(NULL, delimiter))
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
			char fullPath[20];
			if (findExecutable(args[0], fullPath))
			{
				args[0] = fullPath;
			}
			else
			{
				fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
				exit(127);
			}
		}
		execve(args[0], args, environ);
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status); 
			return (exit_status);
		}
	}
	return (0);
}

/**
 * printEnvironment - Prints the system environment variables.
 */
void printEnvironment()
{
    extern char **environ;
    char **env = environ;

    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }
}
