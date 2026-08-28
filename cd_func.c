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
	
	printf("hello\n");
	if (argc > 2)
    {
        printf("cd: too many arguments\n");
		return (1);
    }
	if (*argv[1] != '-')
		getcwd(previous_dir, sizeof(previous_dir));
	if (*argv[1] == '-')
	{
		char temp[1024];

		getcwd(temp, sizeof(temp));
		chdir(previous_dir);
		strcpy(previous_dir, temp);
	}
	else if (argc < 2)
    {
		chdir(_getenv( "HOME"));
    }
	else
    {
        if (chdir(argv[1]) == -1)
        {
            perror("cd");
            return (1);
        }
        return (0);
    }
    return (1);
}
