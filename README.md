# Custom Shell
Is a simple Unix/Linux shell implementation that allows users to execute commands and interact with the system. This shell is developed in C and provides a basic command-line interface for users to input commands and receive responses from the program.
# General Shell Structure

<span>![</span><span>flowchart</span><span>]</span><span>(</span><span>https://raw.githubusercontent.com/ricardovaldesv/holbertonschool-simple_shell/master/images/Simple Shell (1).png</span><span>)</span>

# Features
Interactive Command Execution: Users can enter commands in the shell and receive responses from the program.
Command Execution: The shell can execute various system commands entered by the user.
Environment Variable Printing: The shell can display the system's environment variables using the "env" command.
# Getting Started
To compile and run the Custom Shell on your system, follow these steps:

Clone the repository:
```bash
git clone https://github.com/FoulTrip/holbertonschool-simple_shell.git
```
Compile the source code using GCC:
```c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
Run the shell:
```bash
./hsh
```
# Usage
Once the shell is running, you can interact with it using the command-line interface. Here are some commands you can try:
Entering commands: Type in various commands and press Enter to execute them.
Exiting the shell: Use the "exit" command to exit the shell.
Displaying environment variables: Use the "env" command to print the system environment variables
#  Implementation Details
The Custom Shell is divided into several modules:
main.c: This file contains the main function responsible for creating an interactive loop in which users can enter commands and receive responses from the program.
main.h: Header file containing function declarations and necessary includes.
executeCommand.c: This file defines the executeCommand function, responsible for executing user commands using the execve system call.
path.c: This file defines the findExecutable function, which helps locate the full path of executable commands.
printEnv.c: This file defines the printEnvironment function, which prints the system environment variables.
# Contributions
This project was made possible thanks to the collaborative efforts of [David Vasquez](https://github.com/FoulTrip): Developed the initial shell functionality and main loop and [Ricardo Valdes](https://github.com/ricardovaldesv): Implemented the command execution and environment printing functions.
