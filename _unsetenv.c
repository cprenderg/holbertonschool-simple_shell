#include "main.h"
/**
 * _unsetenv - removes an environment variable
 * @argv: array of pointer to strings of user input
 * @status: status of the shell
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(char **argv, int *status)
{
	int i = 0, len;

	if (argv[1] == NULL)
		return (-1);
	if (strcmp(argv[1], "env") == 0)
	{
		char *env[] = {"env", NULL};

		return (function_search(env, status));
	}

	if (_getenv(argv[1]) == NULL)
	{
		fprintf(stderr, COLOR_RED"./hsh: 1: %s: not found\n"RESET, argv[1]);
		return (-1);
	}

	len = strlen(argv[1]);
	while (environ[i] != NULL)
	{
		if (strncmp(argv[1], environ[i], len) == 0 && environ[i][len] == '=')
		{
			break;
		}
		i++;

	}
	while (environ[i] != NULL)
	{
		environ[i] = environ[i + 1];
		i++;
	}
	return (0);
}
