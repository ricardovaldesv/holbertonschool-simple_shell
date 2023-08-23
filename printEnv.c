#include "main.h"

/**
 * printEnvironment - Prints the system environment variables.
 */
void printEnvironment()
{
    char **env = environ;

    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }
}
