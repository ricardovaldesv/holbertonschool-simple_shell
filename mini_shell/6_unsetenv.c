#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _unsetenv(const char *name) 
{
	int i, x, j, env_var_count;
	char **new_environ;

	if (name == NULL)
	{
		return (-1); 
	} 
	else
	{
		int name_length = strlen(name);
		for (i = 0; environ[i] != NULL; i++)
				{
				if (strncmp(environ[i], name, name_length) == 0 
						&& environ[i][name_length] == '=') 
				{
				break; 
				}
				}
				if (environ[i] == NULL)
				{
				return (-1);
				}

				env_var_count = 0;
				while (environ[env_var_count] != NULL)
				{
				env_var_count++;
				}
				new_environ = malloc(sizeof(char *) * env_var_count);
				if (new_environ == NULL) 
				{
					return (-1);
				}
				x = 0;
				for (j = 0; environ[j] != NULL; j++)
				{
					if (j != i)
					{
						new_environ[x] = environ[j];
						x++;
					}
				}
				new_environ[x] = NULL;
				free(environ);
				environ = new_environ;
				return 0;
	}
}

int main() 
{
	char *path, *miVar, *mmiVar;

	setenv("MI_VARIABLE", "123", 1);

	path = getenv("PATH");
	printf("PATH: %s\n", path);

	miVar = getenv("MI_VARIABLE");
	printf("MI_VARIABLE: %s\n", miVar);

	_unsetenv("MI_VARIABLE");

	mmiVar = getenv("MI_VARIABLE");
	if (mmiVar == NULL) 
	{
		printf("MI_VARIABLE: No se encontró\n");
	}
	else
	{
		printf("MI_VARIABLE: %s\n", mmiVar);
	}
	return 0;
}

