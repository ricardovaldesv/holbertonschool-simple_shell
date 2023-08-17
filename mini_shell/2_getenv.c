#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name) 
{
	int i = 0;
	char *ret = NULL;
	char **ptenv = environ;

	while (ptenv[i] != NULL) 
	{
		if (strncmp(ptenv[i], name, strlen(name)) == 0 && ptenv[i][strlen(name)] == '=')
		{
			ret = ptenv[i] + strlen(name) + 1;
			return (ret);
		}
		i++;
	}
	return (ret);
}
