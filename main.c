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
	char *user_input, **argv;
	int i, argc, command, user_input_len, command_table_size, interactive;
	historylist_t *history_head;

	char directory_path[1024];

	signal(SIGINT, no_sigint);
	printbanner();	
	command_table_size = sizeof(command_table) / sizeof(command_table[0]);
	interactive = isatty(STDIN_FILENO);
	history_head = NULL;
	while (1)
	{
		if (interactive)
		{
			 /* printing prompt */
			getcwd(directory_path, sizeof(directory_path));
			printf("%s$ ", directory_path);
		}
		user_input = getline_reader();
		history_head = history_func(user_input, history_head);

		if (user_input != NULL)
		{
			user_input_len = strlen(user_input);
			user_input[user_input_len - 1] = '\0';
		}
		argc = get_argc(user_input);/* Getting argc */
		if (argc == 0) /* no user input so start loop again */
			continue;

		argv = get_argv(argc, user_input);/* Creating argv */
		i = 0;
		command = 0;
		if (strcmp(argv[0], "history") == 0)
		{
			print_history(history_head);
			command = 1;
		}
		while (i < command_table_size)
		{
			if (strcmp(argv[0], command_table[i].command) == 0)
			{
				if (strcmp(argv[0], "exit") == 0)
				{
					free(user_input);
					free(argv);
					exit (0); /* felix please help i dont know how to free because argv is attached to user_input */
				}
				command_table[i].function(argc, argv);
				command = 1;
				break;
			}
			i++;
		}
		if (command == 0)
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
