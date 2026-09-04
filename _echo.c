#include "main.h"
int _echo(char **argv, int *status)
{
	pid_t pid = getpid();
	int argc = 1, i = 0;

	if (argv[1] == NULL)
		printf("\n");
	else if (argv[1][0] == '$') 
	{
		if (argv[1][1] == '$')
			printf("%d", (int)pid);
		else if (argv[1][1] == '?')
			printf("%d", *status);
		i += 2;
	}

	while (argv[argc])
	{
		while (argv[argc][i])
		{
			if (argv[argc][i] == '"')
				i++;
			putchar(argv[argc][i]);
			i++;
		}
		argc++;
		i = 0;
	}
	putchar('\n');
	return (0);
}