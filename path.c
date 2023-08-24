#include "main.h"
#include <stdbool.h>

/**
 * findExecutable - Find Executable path
 *
 * @command: line of command
 * @fullPath: path
 *
 *Return: bool.
 */

bool findExecutable(char *command, char *fullPath)
{
	char *path = getenv("PATH");
	char *token = strtok(path, ":");

	while (token != NULL)
	{
		snprintf(fullPath, 20, "%s/%s", token, command);
		if (access(fullPath, X_OK) == 0)
		{
			return (true);
		}
		token = strtok(NULL, ":");
	}
	return (false);
}
