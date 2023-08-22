#include "executeCommand.h"

/**
 * executeCommand - It is responsible for executing a
 *                  command on a Unix or Linux system.
 * @command: string of input
 */
void executeCommand(const char *command)
{
	const char *delimiter = " ";
	char *copyCommand = strtok(strdup(command), delimiter);
	pid_t child_pid;
	int argIndex = 1;
	char *args[20];
	args[0] = copyCommand;

	if (copyCommand == NULL)
	{
		return;
	}

	while (argIndex < (20 - 1))
	{
		args[argIndex] = strtok(NULL, delimiter);
		if (args[argIndex] == NULL)
		{
			break;
		}
		argIndex++;
	}

	args[argIndex] = NULL;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error when creating a child process");
		free(copyCommand);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(copyCommand, args, NULL);
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;
		wait(&status);
		free(copyCommand);
	}

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
