#include "main.h"
/**
 * _getenv - returns the value of an the environment variable
 * @name: name of environment variable to get value of
 *
 * Return: pointer to string of environment variable value, or NULL on failure
 */
char *_getenv2(const char *name)
{
	extern char **environ;
	int i, len;

	i = 0;
	
    len = strlen(name);

    while (environ[i] != NULL)
	{
		if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
        {
            return (environ[i] + len + 1);
        }
        i++;
	}
	return (NULL);
}
