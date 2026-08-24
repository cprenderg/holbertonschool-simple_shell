#include "main.h"
int main(int ac, char **av)
{
	char *user_input;
	int user_input_len;
	char exit[] = "exit";
	int command_table_size;
	int i;
	char *token;
	char **argv;
	int argc;
	char *temp;

	printbanner();
	static const command_t command_table[] = {
		{"exit", exit_func},
		{"ls", ls_func},
		{"cd", cd_func}
	};
	command_table_size = sizeof(command_table) / sizeof(command_table[0]);

	while (1)
	{
		user_input = line_reader();
		if (user_input != NULL)
		{
			user_input_len = strlen(user_input);
			user_input[user_input_len - 1] = '\0';
		}
		temp = strdup(user_input);
		/* Getting argc */
		argc = 0;
		token = strtok(user_input, " ");
		while (token != NULL)
		{
			argc++;
			token = strtok(NULL, " ");
		}
		/* Creating argv */
		argv = malloc((argc + 1) * sizeof(char *));
		token = strtok(temp, " ");
		i = 0;
		while (token != NULL)
		{
			argv[i] = token;
			/* strtok continues from the previous word */
			token = strtok(NULL, " ");
			i++;
		}
		argv[i] = NULL;
		i = 0;
		if (function_search(argv) == 1)
		{
			printf("argc : %i", argc);
			printf("Command execution failed\n");
			i = 1;
		}
		while (i < command_table_size && i != 1)
		{
			if (strcmp(argv[0], command_table[i].command) == 0)
				{
					command_table[i].function(argc, argv);
					break;
				}
			i++;
			if (i == command_table_size)
			{
				printf("Error: please choose a valid command\n");
			}
		}
		if (strcmp(user_input, exit) == 0)
		{
			break;
		}
		i = 0;
		free(argv);
		user_input = NULL;
	}
	printf("You said to exit\n");
	return (0);
}
