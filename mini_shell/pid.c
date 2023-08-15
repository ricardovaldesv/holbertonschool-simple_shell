#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	pid_t myp_pid;
	my_pid = getpid();
	myp_pid = getppid();
	printf("My ID process: %u\nMy  Parents ID is: %u\n", my_pid, myp_pid);
	return (0);
}
