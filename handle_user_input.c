#include "main.h"
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
			return (0);
		}
	}
	if (neg == 1)
		sum = sum * -1;
	return (sum);
}

/**
 * check_command - attempts to execute user command
 * @argc: amount of user input
 * @argv: array of pointers to user input
 * @status: variable to store error codes
 * @history_h: head of history list
 *
 * Return: Error status
 */
int check_command(int argc, char **argv, historylist_t *history_h, int *status)
{
	int i = 0, error = 0;

	if (strcmp(argv[0], "exit") == 0)
	{
		if (argv[1] != NULL)
			*status = _atoi(argv[1]);
		while (i < argc)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
		return (0);
	}
	else if (strcmp(argv[0], "cd") == 0)
		error = cd_func(argc, argv);
	else if (strcmp(argv[0], "history") == 0)
		print_history(history_h);
	else if (strchr(argv[0], '/') != NULL)
		error = path_execution(argv, status);
	else if (strcmp(argv[0], "unsetenv") == 0)
		error = _unsetenv(argv[1]);
	else
	{
		error = function_search(argv, status);
		if (error == 1)
		{
			printf(COLOR_RED"./hsh: 1: %s: not found\n"RESET, argv[0]);
			return (1);
		}
		else if (error > 1)
		{
			fprintf(stderr, " ");
			*status = 127;
			return (1);
		}
	}
	return (error);
}
/**
 * handle_input - attempts to execute user command
 * @user_input: the user input string
 * @status: variable to store error codes
 * @history_h: head of history list
 *
 * Return: return 0 on success, 1 if want_exit (for now)
 */
int handle_input(char *input, historylist_t *history_h, int *status)
{
	int argc, i, error = 0;
	char **argv, specifier[] = {'|', '&', ';'};
	
	if (strpbrk(input, specifier))
	{
		error = handle_condition(input, history_h, status);
	}
	else
	{
		argc = get_argc(input);/* Getting argc */
		argv = get_argv(argc, input);/* Creating argv */

		error = check_command(argc, argv, history_h, status);
	}
	i = 0;
	if (error != 1)
	{
		while (i < argc)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	return (error);
}
