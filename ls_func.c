#include "main.h"
#include <dirent.h>
#include <stdlib.h>
/*
typedef struct ls_func_s{
    char *flag;
    int (*function)(void);
} ls_func_t;

ls_func_t *build_ls_struct()
{

} */
int _dir_len(char *name)
{
	DIR *dir;
	struct dirent *entry;
	int dir_len;

	/* open directory opendir() opens path where "." is current directory */
	dir = opendir(name);
	/* add dir == NULL failure codes*/
	if (dir == NULL)
	{
		return (-1);
	}
	/* Get the amount of files in dir */
	entry = readdir(dir);
	dir_len = 0;
	while (entry != NULL)
	{
		dir_len++;
		entry = readdir(dir);
	}
	closedir(dir);
	return (dir_len);
}
char **dir_array(char *name, int dir_len)
{
	DIR *dir;
	struct dirent *entry;
	char **arr;
	int i;

	/* allocate memory to array of strings */
	arr = malloc(dir_len * sizeof(char *));
	if (arr == NULL)
	{
		return (NULL);
	}

	/* copying directory into a list */
	dir = opendir(name);
	i = 0;
	entry = readdir(dir);
	while (entry != NULL)
	{
		arr[i] = malloc(strlen(entry->d_name + 1));
		strcpy(arr[i], entry->d_name);
		entry = readdir(dir);
		i++;
	}
	closedir(dir);
	return (arr);
}
int ls_func(int argc, char **argv)
{
	/*DIR *dir;
	struct dirent *entry; */
	int i;
	char **arr;
	int dir_len;

	if (argc)
	{
		dir_len = _dir_len(".");
		arr = dir_array(".", dir_len);

		/* NOW CHECK FLAGS */
		/* if no flags print in order */
		quick_sort(arr, (size_t)dir_len);
		i = 0;
		while (i < argc)
		{
			if (argv[0][0] == 'l')
			{
				printf("YES\n");
			}
			i++;
		}
		/* printing arr */
		i = 0;
		while (i < dir_len)
		{
			printf("%s", arr[i]);
			i++;
			if (i != dir_len)
			{
				printf("  ");
			}
		}
		printf("\n");
		/* Freeing memory */
		while (i < dir_len)
		{
			free(arr[i]);
		}
		free(arr);
		return (0);
	}
	return (-1);
}
