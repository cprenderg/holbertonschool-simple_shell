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
		/* Loops through the array to get memory */
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
		if (i > 0) /* Adds a space after each argv */
			strcat(input, " ");

		strcat(input, argv[i]); /* Appending argv to input */
		i++;
	}

	return (input);
}
/**
 * cd_setpwd - helper function to set PWD after cd
 * @previous_dir: OLDPWD before cd
 * @change_location: value given after cd
 * @pwd: directory changed to after cd
 *
 * Return: full string for PWD
 */
char *cd_setpwd(char *previous_dir, char *change_location, char *pwd)
{
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
		change_location = strrchr(pwd, '/'); /* find the last location of '/' */
		*change_location = '\0';
	}
	else
	{
		char *temp;

		free(pwd);
		if (change_location[0] == '/') /* if cd with /new_dir */
			pwd = _strdup(change_location);
		else /* Appending new dir to oldpwd */
		{
			temp = _strdup(_getenv("OLDPWD"));
			pwd = malloc(strlen(temp) + strlen(change_location) + 2);
			sprintf(pwd, "%s/%s", temp, change_location);
			free(temp);
		}
	}
	return (pwd);
}
/**
 * get_change_location - helper function to get location to cd to
 * @argc: number of arguments in user input
 * @argv: array of pointers to strings of user input
 * @previous_dir: PWD before cd
 * @pwd: PWD after cd
 * @input: user input as string
 * @old_arr: array used to change OLDPWD
 * @env_head: head of env list
 * @status: status of shell
 *
 * Return: string of directory to change to
 */
char *get_change_location(int argc, char **argv, char *previous_dir,
	char *pwd, char *input, char **old_arr, envlist_t **env_head, int *status)
{
	char *change_location;

	if (argc < 2 || argv[1] == NULL) /* For input cd */
	{
		change_location = _getenv("HOME");
		if (change_location == NULL || change_location[0] == '\0')
		{
			free(previous_dir);
			free(pwd);
			free(input);
			return (NULL);
		}
	}
	else if (strcmp(argv[1], "-") == 0) /* For input cd - */
	{
		if (previous_dir == NULL || previous_dir[0] == '\0')
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
	return (change_location);
}
/**
 * cd_func - changes current working directory
 * @argc: number of arguments
 * @argv: array of arguments
 * @env_head: head of env list
 * @status: status of shell
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
	change_location = get_change_location(argc, argv, previous_dir,
		pwd, input, old_arr, env_head, status);
	if (change_location == NULL)
		return (1);
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
	pwd = cd_setpwd(previous_dir, change_location, pwd);
	pwd_arr[2] = pwd;
	free(input);
	input = build_input(4, pwd_arr);
	_setenv(pwd_arr, env_head, input, status);
	free(previous_dir);
	free(input);
	free(pwd);
	return (0);
}
