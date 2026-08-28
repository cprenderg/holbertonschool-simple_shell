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
	
    printf("getting len\n");
    len = strlen(name);
    printf("len = %d\n", len);

    while (environ[i] != NULL)
	{
		if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
        {
			printf("returning: %s\n", environ[i] + len);
            return (environ[i] + len);
        }
        i++;
	}
	return (NULL);
}
