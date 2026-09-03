#include "main.h"
/**
 * build_input - creates a new string combining argv
 * @argv: array of pointers to strings of user input
 * @argc: number of arguments
 *
 * Return: pointer to combined string
 */
char *build_input(int argc, char **argv)
{
	int i, j, mem;
	char *input;

	i = 0;
	mem = 0;

	while (i < argc)
	{
		j = 0;
		
		while (argv[i] != NULL && argv[i][j] != '\0')
		{
			j++;
		}
		mem += j + 1;
		i++;
	}

	input = malloc(mem * sizeof(char));
	input[0] = '\0';
	i = 0;

	while (i < argc && argv[i] != NULL)
	{
		if (i > 0)
			strcat(input, " ");

		strcat(input, argv[i]);
		i++;
	}

	return (input);
}

/**
 * cd_func - changes current working directory
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on failure
 */
int cd_func(int argc, char **argv, envlist_t **env_head, int *status)
{
	char *input, *change_location, *previous_dir, *pwd;
	char *old_arr[4] = {"setenv", "OLDPWD", NULL, NULL};
	char *pwd_arr[4] = {"setenv", "PWD", NULL, NULL};

	if (argc > 2)
	{
		printf(COLOR_RED"cd: too many arguments\n"RESET);
		return (1);
	}

	previous_dir = _strdup(_getenv("OLDPWD"));
	pwd = _strdup(_getenv("PWD"));
	old_arr[2] = pwd;
	input = build_input(4, old_arr);

	if (argc < 2 || argv[1] == NULL)
	{
		change_location = _getenv("HOME");
		if (change_location == NULL || change_location[0] == '\0')
		{
			free(previous_dir);
			free(pwd);
			free(input);
			return (1);
		}
	}
	else if (strcmp(argv[1], "-") == 0)
	{
		if (previous_dir[0] == '\0')
		{
			_setenv(old_arr, env_head, input, status);
			free(previous_dir);
			previous_dir = _strdup(_getenv("OLDPWD"));
		}
		change_location = previous_dir;
	}
	else
	{
		change_location = argv[1];
	}
	_setenv(old_arr, env_head, input, status);
	if (chdir(change_location) == -1)
	{
		if (errno == EACCES || errno == ENOENT)
			fprintf(stderr, "./hsh: 1: cd: can't cd to %s\n", change_location);
		else
			perror("cd");
		free(previous_dir);
		free(pwd);
		free(input);
		return (1);
	}

	if (previous_dir != NULL && strcmp(change_location, previous_dir) == 0)
	{
		free(pwd);
		pwd = _strdup(change_location);
		printf("%s\n", previous_dir);
	}	
	else if (strcmp(change_location, _getenv("HOME")) == 0)
	{
		free(pwd);
		pwd = _strdup(_getenv("HOME"));
	}
	else if (strcmp(change_location, "..") == 0)
	{
		free(pwd);
		pwd = _strdup(_getenv("OLDPWD"));
		change_location = strrchr(pwd, '/');
		*change_location = '\0';
	}
	else
	{
		char *temp;
		
		temp = _strdup(_getenv("OLDPWD"));
		free(pwd);
		pwd = malloc(strlen(temp) + strlen(change_location) + 2);
		sprintf(pwd, "%s/%s", temp, change_location);
		free(temp);
	}
	
	pwd_arr[2] = pwd;

	free(input);
	input = build_input(4, pwd_arr);
	_setenv(pwd_arr, env_head, input, status);
	free(previous_dir);
	free(input);
	free(pwd);
	return (0);
}
