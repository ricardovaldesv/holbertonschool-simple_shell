#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	//int i;
	pid_t child_pid;
	//pid_t current_pid;
	int status;
	char *tokens[3];
	int tk_c = 0;

	printf("cisfun$ ");
	read = getline(&line, &len, stdin);

	if (read != -1)
	{
		char *token = strtok(line, "/");

		while (token != NULL && tk_c < 3)
		{
			tokens[tk_c] = token;//creo array argumentos
			tk_c++;
			token = strtok(NULL, "/");
		} //hasta aqui tengo array tokensi
		//printf("Tokens:\n");
		//for (int i = 0; i < tk_c; i++) 
		//{
		//	printf("%s\n", tokens[i]);
		//}

		char *array2[tk_c - 1];
		for (int i = 1; i < tk_c; i++)
		{
			array2[i - 1] = tokens[i];
		}

		
		child_pid = fork();// creo hijo

		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		else if (child_pid == 0)
		{
			//char *args[] = {"ls", NULL};
			execve(tokens[0], array2, NULL);
			perror("Execve failed");
			return (1);
		}
		else
		{
			wait(&status);
		
		}
		
	}
		
	else
	{
		printf("Error reading the line.\n");
		return (1);
	}

	free(line);
	return(0);

}
