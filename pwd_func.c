#include "main.h"
/**
 * pwd_func - prints the current working directory
 *
 * Return: 0 if successful, 1 if fails
 */
int pwd(void)
{
	char *cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		perror("pwd");
		return (1);
	}
	printf("%s\n", cwd);
	free(cwd);
	return(0);
}
