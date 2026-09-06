#include "main.h"
/**
* _echo - a remade echo function using recursion
* @argv: all the arguments to be printed
* @status: variable storing the previous exit status
* @spaces: lets the function know wether to add a space or not
* Return: 0 always
*/
int _echo(char **argv, int *status)
{
	pid_t pid = getpid();
	int i = 0, error = 1;
	char *env;

	if (argv[0] == NULL)
	{
		putchar('\n');
		return (0);
	}
	while (argv[0][i])
	{
		if (argv[0][i] == '$' && argv[0][i + 1] != '\0') /*checks characters following a '$' char */
		{
			if (argv[0][i + 1] == '$')
				error = printf("%d", (int)pid);
			else if (argv[0][i + 1] == '?')
				error = printf("%d", *status);
			else
			{
				env = _getenv(argv[0] + i + 1);
				if (env == NULL)
					break;
				printf("%s", env);
			}
			if (error != 0) /* if anything printed*/
				i +=2;
		}
		putchar(argv[0][i]);
		i++;
	}
	if (argv[1] != NULL)
		putchar(' ');
	_echo(argv + 1, status);
	return (0);
}
