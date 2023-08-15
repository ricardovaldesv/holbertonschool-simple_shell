#include <stdio.h>
#include <stdlib.h>

/**
 * main - This fprogram that prints "$ ", wait for the user to enter a command, prints it on the next line
 *
 * Return: 0, -1 error
 */


int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$ ");
	read = getline(&line, &len, stdin);

	if (read != -1)
	{
		printf("%s", line);
	} 
	else 
	{
		printf("Error reading the line.\n");
	}

	free(line);
	return 0;
}
