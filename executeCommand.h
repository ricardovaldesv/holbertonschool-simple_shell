#ifndef EXECUTE_COMMAND_H
#define EXECUTE_COMMAND_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void executeCommand(const char *command);
void printEnvironment();

#endif
