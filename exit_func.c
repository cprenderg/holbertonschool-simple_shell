#include "main.h"
/**
 * exit_func - exits shells with a status
 * @argc: amount of user input
 * @argv: array of pointers to user input
 *
 * Return: Exit status
 */
int exit_func(int argc, char **argv)
{
	if (argc > 1)
		return (1);
	if (strcmp(argv[0], "exit") == 0)
	{
		exit(0);
	}
	return (1);
}
