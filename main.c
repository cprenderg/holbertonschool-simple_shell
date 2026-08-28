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
	int i, argc, command, command_table_size, interactive, want_exit;
	historylist_t *history_head;

	history_head = NULL;
	printbanner();
	signal(SIGINT, no_sigint);
	command_table_size = sizeof(command_table) / sizeof(command_table[0]);
	interactive = isatty(STDIN_FILENO);
	

	while (1)
	{
		i = command = want_exit = 0;
		if (interactive)
		{
			getcwd(directory_path, sizeof(directory_path));
			printf("%s$ ", directory_path); /* printing prompt */
		}

		if ((user_input = getline_reader()) == NULL)
			continue;
		history_head = history_func(user_input, history_head);

		argc = get_argc(user_input);/* Getting argc */
		argv = get_argv(argc, user_input);/* Creating argv */

		while (i < command_table_size) /* this is so unnecessary, we have 1 command only :')*/
		{
			if (strcmp(argv[0], command_table[i].command) == 0)
			{
				if (strcmp(argv[0], "exit") == 0)
					want_exit = 1;
				else
					command_table[i].function(argc, argv);
				command = 1;
				break;
			}
			i++;
		}
		if (command == 0 && (strcmp(argv[0], "history") == 0))
			print_history(history_head);
			/*temporary fixes*/
		if (command == 0 && user_input[0] != '/' && strcmp(user_input, "history") != 0)
			if ((function_search(argv)) == 1)
				printf("Command execution failed\n");

		free(argv);
		free(user_input);
		if (want_exit)
		{
			free_history(history_head);
		}
	}
	return (0);
}
