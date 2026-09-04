#include "main.h"
#include <sys/types.h>
/**
 * _atoi - converts a string to an integer
 * @argv: the string to convert
 * Return: converted integer
 */
int _atoi(char *argv)
{
	int i = 0, sum = 0, neg = 0;

	if (argv[i] == '-')
	{
		neg = 1;
		i++;
	}
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
		{
			sum = sum * 10 + (argv[i] - '0');
			i++;
		}
		else
		{
			fprintf(stderr, COLOR_RED"./hsh: 1: exit: Illegal number: %s"RESET, argv);
			return (1);
		}
	}
	if (neg == 1)
		sum = sum * -1;
	return (sum);
}

/**
 * check_command - attempts to execute user command
 * @user_input: pointer to user_input string
 * @argc: amount of user input
 * @argv: array of pointers to user input
 * @status: variable to store error codes
 * @history_h: head of history list
 * @env_head: head of env list
 *
 * Return: Error status
 */
int check_command(char *user_input, int argc, char **argv,
	historylist_t *history_h, int *status, envlist_t **env_head)
{
	int error = 0;

	if(argv[0] == NULL)
		return (1);
	if (strcmp(argv[0], "exit") == 0)
	{
		if (argv[1] != NULL)
			*status = _atoi(argv[1]);
		if (*status == 1)
			return (0);
		return (1);
	}
	else if (strcmp(argv[0], "cd") == 0)
		cd_func(argc, argv, env_head, status);
	else if (strcmp(argv[0], "history") == 0)
		print_history(history_h);
	else if (strcmp(argv[0], "setenv") == 0)
		_setenv(argv, env_head, user_input, status);
	else if (strchr(argv[0], '/') != NULL)
		error = path_execution(argv, status);
	else if (strcmp(argv[0], "unsetenv") == 0)
		error = _unsetenv(argv, status);
	else if (strcmp(argv[0], "echo") == 0)
		error = _echo((argv + 1), status, 0);
	else
	{
		error = function_search(argv, status);
		if (error == 2)
			printf(COLOR_RED"./hsh: 1: %s: not found\n"RESET, argv[0]);
		else if (error > 2)
			fflush(stderr);
	}
	return (error);
}
/**
 * handle_input - attempts to execute user command
 * @input: the user input string
 * @status: variable to store error codes
 * @history_h: head of history list
 * @env_head: head of env list
 *
 * Return: return 0 on success, 1 if want_exit (for now)
 */
int handle_input(char *input, historylist_t *history_h,
	int *status, envlist_t **env_head)
{
	int argc, found_spec = 0, i = 0, error = 0;
	char **argv, *temp_input, specifier[] = "|&;";

	temp_input = _strdup(input);
	if (_strpbrk(input, specifier))
	{
		error = handle_condition(input, history_h, status, env_head);
		found_spec = 1;
	}
	else
	{
		argc = get_argc(input);/* Getting argc */
		argv = get_argv(argc, input);/* Creating argv */
		error = check_command(temp_input, argc, argv, history_h, status, env_head);
	}
	if (!found_spec)
	{
		i = 0;
		while (argv[i] != NULL)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	free(temp_input);
	return (error);
}
