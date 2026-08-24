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
    if (argc < 2)
    {
        /* fprintf chooses where output is printed */
        fprintf(stderr, "invalid arguments\n");
        return (1);
    }
    if (chdir(argv[1]) == -1)
    {
        perror("cd");
        return (1);
    }
}
