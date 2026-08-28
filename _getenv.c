#include "main.h"
/**
 * _getenv - returns the value of an the environment variable
 * @name: name of environment variable to get value of
 *
 * Return: pointer to string of environment variable value, or NULL on failure
 */
char *_getenv(const char *name)
{
	extern char **environ;
	int i;
	char *token, *temp;

	i = 0;
	while (environ[i] != NULL)
	{
		temp = strdup(environ[i]);
		token = strtok(temp, "=");
		if (token != NULL && strcmp(token, name) == 0)
		{
			token = strtok(NULL, "=");
			if (token == NULL)
			{
				free(temp);
				return (NULL);
			}
			return (token);
		}
		free(temp);
		i++;
	}
	return (NULL);
}
