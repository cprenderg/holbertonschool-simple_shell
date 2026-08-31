#include "main.h"
/** handle_user_input - attempts to execute user command
 * @argc: amount of arguments from user input
 * @argv: pointer to array of strings of user input
 * @start: where to start using strings in argv
 * @history_head: head of history list
 *
 * Return: return 0 on success, 1 if want_exit (for now)
 */
int handle_user_input(char *user_input, historylist_t *history_head)
{
    int argc, i;
    char **argv;

    argc = get_argc(user_input);/* Getting argc */
	argv = get_argv(argc, user_input);/* Creating argv */
	if (strcmp(argv[0], "exit") == 0)
	{
		i = 0;
		while (i < argc - 1)
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
        print_history(history_head);
	else if (strchr(argv[0], '/') != NULL)
		path_execution(argv);
	else
    {
        if ((function_search(argv)) == 1)
            printf("'%s': command not found\n", argv[0]);
    }

    i = 0;
    while (i < argc - 1)
    {
        free(argv[i]);
        i++;
    }
    free(argv);
    return (0);
}

