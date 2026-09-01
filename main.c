#include "main.h"
/**
*no_sigint - signal handling for CTRL + C
*@needstobehere: the integer sent CTRL + C
*/
void no_sigint(int needstobehere)
{
	char directory_path[1024];

	getcwd(directory_path, sizeof(directory_path));
	(void)needstobehere;
	printf("\n%s$ ", directory_path);
	fflush(stdout);
}
/**
* main - the main file of a simple shell recreation project
* Return: exit status
*/
int main(void)
{
	char *user_input, directory_path[1024];
	int i, command, interactive, want_exit, last_status = 0;
	historylist_t *history_head;

	history_head = NULL;
	signal(SIGINT, no_sigint);
	interactive = isatty(STDIN_FILENO);
	/**
	*if (interactive)
	*	printbanner();
	*/

	while (1)
	{
		i = command = want_exit = 0;
		if (interactive)
		{
			getcwd(directory_path, sizeof(directory_path));
			printf("%s$ ", directory_path); /* printing prompt */
		}
		user_input = getline_reader();

		if (user_input == NULL)
			break;
		if (*user_input == '\n')
		{
			free(user_input);
			continue;
		}
		history_head = history_func(user_input, history_head);
		if (!command)
			want_exit = handle_input(user_input, history_head, &last_status);

		free(user_input);
		if (want_exit == 1)
			break;
	}
	free_history(history_head);
	return (last_status);
}
