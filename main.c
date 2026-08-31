#include "main.h"


/** static const command_t command_table[] = {
 		{"exit", exit_func},
 		{"cd", cd_func}
 	};*/

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
	char *user_input, directory_path[1024];
	int i, command, interactive, want_exit;
	historylist_t *history_head;
	char *specifier_table[] = {"||", "&&", NULL};

	history_head = NULL;
	signal(SIGINT, no_sigint);
	interactive = isatty(STDIN_FILENO);
	if (interactive)
		printbanner();

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

		while (specifier_table[i] != NULL)
		{
			if (strstr(user_input, specifier_table[i]))
			{
				want_exit = handle_condition(user_input, *specifier_table[i]);
				command = 1;
			}
			i++;
		}
		if (!command)
			want_exit = handle_user_input(user_input, history_head);
		free(user_input);

		if (want_exit || !interactive)
		{
			free_history(history_head);
			break;
		}
	}
	return (0);
}
