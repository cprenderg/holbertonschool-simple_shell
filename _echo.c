#include "main.h"
int _echo(char **argv, int *status, int spaces)
{
	pid_t pid = getpid();
	int argc = 1, i = 0, error = 0;
	char *env;

	if (argv[0] == NULL)
	{
		putchar('\n');
		return (0);
	}

	if (argv[0][0] == '$' && argv[0][1] != '\0')
	{
		if (argv[0][1] == '$')
			printf("%d", (int)pid);
		else if (argv[0][1] == '?')
			printf("%d", *status);
		else
		{
			env = _getenv(argv[0] + 1);
			if (env == NULL)
				;
			else
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
	argv--;
	return (0);
}
