#include "main.h"
#include <stdio.h>
/**
 * cd_func - changes current working directory
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on failure
 */
int cd_func(int argc, char **argv)
{
	static char previous_dir[1024];

	if (argc > 2)
	{
		printf("cd: too many arguments\n");
		return (1);
	}
	else if (argc < 2 || strcmp(argv[1], "") == 0)
	{
		if (_getenv("HOME") == NULL)
			return (1);
		getcwd(previous_dir, sizeof(previous_dir));
		chdir(_getenv("HOME"));
		return (0);
	}
	if (*argv[1] != '-')
		getcwd(previous_dir, sizeof(previous_dir));
	if (strcmp(argv[1], "-") == 0)
	{
		char temp[1024];

		getcwd(temp, sizeof(temp));
		if (previous_dir[0] == '\0')
		{
			printf("%s\n", temp);
			return (0);
		}
		chdir(previous_dir);
		printf("%s\n", previous_dir);
		strcpy(previous_dir, temp);
	}
	else
	{
		if (chdir(argv[1]) == -1)
		{
			if (errno == EACCES)
			{
				fprintf(stderr, "./hsh: 1: cd: can't cd to /root\n");
			}
			else
				perror("cd");
			return (1);
		}
		return (0);
	}
	return (1);
}
