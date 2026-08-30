#include "main.h"
/** handle_user_input - attempts to execute user command
 * @argc: amount of arguments from user input
 * @argv: pointer to array of strings of user input
 * @start: where to start using strings in argv
 * @history_head: head of history list
 *
 * Return: return 0 on success, 1 if want_exit (for now)
 */
int handle_user_input(int argc, char **argv, int start, historylist_t *history_head)
{
        if (strcmp(argv[start], "exit") == 0)
            return (1);
        else if (strcmp(argv[start], "cd") == 0)
            cd_func(argc, argv);
        else if (strcmp(argv[start], "history") == 0)
            print_history(history_head);
        else
        {
            if ((function_search(argv)) == 1)
                printf("Command execution failed\n");
        }
    return (0);
}

