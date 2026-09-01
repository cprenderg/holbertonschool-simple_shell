#include "main.h"
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
