#include "main.h"

int _unsetenv(const char *name)
{
	int i = 0, len;

	len = strlen(name);

	if (_getenv(name) == NULL)
	{
		fprintf(stderr, COLOR_RED"./hsh: 1: %s: not found\n"RESET, name);
		return (-1);
	}

	while (environ[i] != NULL)
	{
		if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
		{
			break;
		}
		i++;

	}
	while(environ[i] != NULL)
	{
		environ[i] = environ[i + 1];
		i++;
	}
	return (0);
}
