#include <stdio.h>


/**
 * main - This funtion print all arguments.
 *
 * @ac : is a number of arguments
 * @av: array of pointer to string
 * Return: 0
 */

int main(int ac, char **av)

{
	int i;
	(void)ac;

	for (i = 0; av[i] != NULL; i++)
	{
		printf("The Argument %d is  %s\n", i, av[i]);
	}
	return (0);
}
