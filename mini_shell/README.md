# MINI SHELL

## 0. getppid : 
> program that prints the **PID** of the parent process. 
- File: pid.c,  executable : mypid

## 1. /proc/sys/kernel/pid_max:
> shell script that prints the maximum value a process ID can be.
- File : 1_max_pid.sh

## 0. av:
> program that prints all the arguments, without using ac.
- file: 0_av.c, executable : 0_av.

## 1. Read line : 
> program that prints "$ ", wait for the user to enter a command, prints it on the next line.
- file: prompt.c, executable : prompt

## 2. command line to av
>Function that splits a string and returns an array of each word of the string.
- file: prompt_token.c, executable : prompt_token

## Executing a program
> Example function execve
- file: exec.c, executable : exec

## Creating processes
> Example **fork**
- file: fork.c and fork2, executable : fork and fork2

## Wait
> The wait system call (man 2 wait) suspends execution of the calling process until one of its children terminates.
- file: wait.c, executable : wait

## Exercise: fork + wait + execve
> program that executes the command ls -l /tmp in 5 different child processes. Each child should be created by the same process (the father). Wait for a child to exit before creating a new child.
- file: 5_different_child_process.c, executable : 5_different_child_process

## Exercise: super simple shell
> first version of a super simple shell that can run commands with their full path, without any argument.
- file : shell.c executable: shell
## File information
> The stat (man 2 stat) system call gets the status of a file. On success, zero is returned. On error, -1 is returned.
- file : stat.c executable: stat
