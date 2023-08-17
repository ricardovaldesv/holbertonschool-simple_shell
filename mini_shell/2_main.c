#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_getenv(const char *name);

int main()
{
	char *path = _getenv("PATH");
	if (path != NULL) 
	{
		printf("%s\n", path);
	} else
	{
		printf("Variable de entorno no encontrada.\n");
	}
	return (0);
}
