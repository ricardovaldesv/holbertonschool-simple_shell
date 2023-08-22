#include "executeCommand.h"

/**
 * main - Creates an interactive loop in which the 
 *        user can enter commands and receive responses 
 *        from the program.
 * Return: Always 0.
 */

int main()
{
	ssize_t read;
	char *input = NULL;
	size_t len = 0;

	while (1)
	{
		if (isatty(fileno(stdin)))
		{
			printf("#cisfun$ ");
		}

		read = getline(&input, &len, stdin);

		if (read == -1) 
		{
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		else if (strcspn(input, "env") == 0)
		{
			printEnvironment();
		}
		else
		{
			executeCommand(input);
		}
	}

	free(input);
	return (0);
}
