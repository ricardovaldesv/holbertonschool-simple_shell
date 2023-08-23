#ifndef EXECUTE_COMMAND_H
#define EXECUTE_COMMAND_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

extern char **environ;

void executeCommand(char *command);
void printEnvironment();
bool findExecutable(char *command, char *fullPath);


#endif
