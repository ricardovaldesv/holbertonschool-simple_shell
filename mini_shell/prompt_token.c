#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - This  function splits a string and returns an array of each word of the string.
 *
 * Return: 0 success, -1 error
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

	char *token = strtok(line, " ");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	free(line);
	return 0;
}
