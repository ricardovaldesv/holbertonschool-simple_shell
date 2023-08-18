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
    pid_t child_pid;
    int status;

    while (1)
    {
	 char *array2[2];
	    if (isatty(fileno(stdin)))
                {
                        printf("#cisfun$ ");
                }
       
        read = getline(&line, &len, stdin);

        if (read != -1)
        {
            line[strcspn(line, "\n")] = '\0';

	    array2[0] = line;
	    array2[1] = NULL;
	

            child_pid = fork();

            if (child_pid == -1)
            {
                perror("Error:");
                return (1);
            }
            else if (child_pid == 0)
            {
                execve(array2[0], array2, NULL);
                perror("./shell");
                exit (1);
            }
            else
            {
                wait(&status);
            }
        }
        else
        {
            return (0);
        }
	free (line);

    }
    return 0;
}
