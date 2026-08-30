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

		if (strchr(user_input, '|')) 
			handle_pipe(user_input); /* this does nothing at the moment */

		want_exit = handle_user_input(user_input, history_head);

		free(user_input);
		if (want_exit)
		{
			free_history(history_head);
		}
	}
	return (0);
}
