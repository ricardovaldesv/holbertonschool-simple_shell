#include "executeCommand.h"
#include <stdbool.h>

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
