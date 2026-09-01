#include "main.h"
/**
 * handle_user_input - attempts to execute user command
 * @user_input: the user input string
 * @status: variable to store error codes
 * @history_h: head of history list
 *
 * Return: return 0 on success, 1 if want_exit (for now)
 */
int handle_user_input(char *user_input, historylist_t *history_h, int *status)
{
	int argc, i = 0, error = 0;
	char **argv;

	argc = get_argc(user_input);/* Getting argc */
	argv = get_argv(argc, user_input);/* Creating argv */
	if (argv[0] == NULL)
	{
		free(argv);
		return (2); /*pseudo status we can decide later */
	}
	if (strcmp(argv[0], "exit") == 0)
	{
		while (i < argc)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
		return (1);
	}
	else if (strcmp(argv[0], "cd") == 0)
		cd_func(argc, argv);
	else if (strcmp(argv[0], "history") == 0)
		print_history(history_h);
	else if (strchr(argv[0], '/') != NULL)
		error = path_execution(argv, status);
	else
	{
		if ((function_search(argv, status)) == 1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
			*status = 127;
		}
	}
	i = 0;
	while (i < argc)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	return (error);
}

/**
*	char *specifier_table[] = {"||", "&&", NULL};
*
*while (specifier_table[i] != NULL)
*		{
*			if (strstr(user_input, specifier_table[i]))
*			{
*				want_exit = handle_condition(user_input, *specifier_table[i], &status);
*				command = 1;
*			}
*			i++;
*		}
*
*/
