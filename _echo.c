#include "main.h"
/**
* _echo - a remade echo function using recursion
* @argv: all the arguments to be printed
* @status: variable storing the previous exit status
* @spaces: lets the function know wether to add a space or not
* Return: 0 always
*/
int _echo(char **argv, int *status, int spaces)
{
	pid_t pid = getpid();
	int i = 0, error = 0;
	char *env;

	if (argv[0] == NULL)
	{
		putchar('\n');
		return (0);
	}

	if (argv[0][0] == '$' && argv[0][1] != '\0') /*checks characters following a '$' char */
	{
		if (argv[0][1] == '$')
			printf("%d", (int)pid);
		else if (argv[0][1] == '?')
			printf("%d", *status);
		else
		{
			env = _getenv(argv[0] + 1);
			if (env != NULL)
				printf("%s", env);
			error = 1;
		}
		i += 2;
	}
	while (argv[0][i] && error == 0)
	{
		if (argv[0][i] == '"')
			spaces = 1, i++;
		else
		{
			putchar(argv[0][i]);
			i++;
		}
	}
	if (spaces == 1)
		putchar(' ');
	_echo(argv + 1, status, spaces);
	argv--; /*walks it back to so it can be freed in user_input*/
	return (0);
}
