#include "main.h"


static const command_t command_table[] = {
		{"exit", exit_func},
		{"cd", cd_func}
	};
void no_sigint(int needstobehere)
{
	char directory_path[1024];
	getcwd(directory_path, sizeof(directory_path));
	(void)needstobehere;
	printf("\n%s$ ", directory_path);
	fflush(stdout);
}
int main(void)
{
	char *user_input, **argv, directory_path[1024];
	int i, argc, command, user_input_len, command_table_size, interactive;
	historylist_t *history_head;

	history_head = NULL;
	printbanner();
	signal(SIGINT, no_sigint);
	command_table_size = sizeof(command_table) / sizeof(command_table[0]);
	interactive = isatty(STDIN_FILENO);

	while (1)
	{
		i = command = 0;
		if (interactive)
		{
			getcwd(directory_path, sizeof(directory_path));
			printf("%s$ ", directory_path); /* printing prompt */
		}
		if ((user_input = getline_reader(history_head)) == NULL)
			continue;
		history_head = history_func(user_input, history_head);
		
		argc = get_argc(user_input);/* Getting argc */
		argv = get_argv(argc, user_input);/* Creating argv */

		while (i < command_table_size)
		{
			if (strcmp(argv[0], command_table[i].command) == 0)
			{
				if (strcmp(argv[0], "exit") == 0)
				{
					free(user_input);
					free(argv);/* it is fine to free it this way*/
					/*but we need to free history as well
					should probably free everything in a separate function*/
					free(history_head->next->next->user_input);
					free(history_head->next->next);
					free(history_head->next->user_input);
					free(history_head->next);
					free(history_head->user_input);
					free(history_head);
					/*this has 0 leaks with 2 commands + exit command*/
					exit (0); 
				}
				command_table[i].function(argc, argv);
				command = 1;
				break;
			}
			i++;
		}
			/*temporary fixes*/
		if (command == 0 && user_input[0] != '/' && strcmp(user_input, "history") != 0)
		{
			if ((function_search(argv)) == 1)
				printf("Command execution failed\n");
		}
		free(argv);
		free(user_input);
		if (!interactive)
		{
			exit (0);
		}
	}
	return (0);
}
