#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) 

{
	char *path;
	char *token;

	if (argc < 2)
	{
		printf("Usage: %s filename ...\n", argv[0]);
		return (1);
	}

	path = getenv(argv[1]);
	token = strtok(path, ":");

	while (token != NULL) 
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
	return (0);
}
