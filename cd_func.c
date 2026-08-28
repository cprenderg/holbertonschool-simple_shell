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
    if (argc > 2)
    {
        printf("cd: too many arguments\n");
    }
    else if (argc < 2)
    {
        printf("cd: we don't have this capabilty yet\n");
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
