#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite) 
{
	if (name == NULL || value == NULL) {
		return -1;
	}

	int name_length = strlen(name);
	for (int i = 0; environ[i] != NULL; i++) 
	{
		if (strncmp(environ[i], name, name_length) == 0 && environ[i][name_length] == '=') 
		{
			if (!overwrite) 
			{
				return (0);
			}

			char *new_env_var = malloc(strlen(name) + strlen(value) + 2);
			if (new_env_var == NULL) 
			{
				return (-1);
			}
			sprintf(new_env_var, "%s=%s", name, value);
			environ[i] = new_env_var;
			return (0);
		}
	}

	char *new_env_var = malloc(strlen(name) + strlen(value) + 2);
	if (new_env_var == NULL) 
	{
		return (-1);
	}

	sprintf(new_env_var, "%s=%s", name, value);
	int env_var_count = 0;
	while (environ[env_var_count] != NULL) 
	{
		env_var_count++;
	}

	char **new_environ = malloc(sizeof(char *) * (env_var_count + 2));
	if (new_environ == NULL) 
	{
		free(new_env_var);
		return -1;
	}

	for (int i = 0; i < env_var_count; i++)
	{
		new_environ[i] = environ[i];
	}

	new_environ[env_var_count] = new_env_var;
	new_environ[env_var_count + 1] = NULL;
	environ = new_environ;
	return 0;
}

int main()
{
	_setenv("MI_VARIABLE", "123", 1);
	_setenv("OTRA_VARIABLE", "456", 0);

	char *path = getenv("PATH");
	printf("PATH: %s\n", path);

	char *miVar = getenv("MI_VARIABLE");
	printf("MI_VARIABLE: %s\n", miVar);

	char *otraVar = getenv("OTRA_VARIABLE");
	printf("OTRA_VARIABLE: %s\n", otraVar);
	return (0);
}
