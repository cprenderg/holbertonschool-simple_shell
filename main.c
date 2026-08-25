#include "main.h"

static const command_t command_table[] = {
		{"exit", exit_func},
		{"cd", cd_func}
	};
int main(void)
{
	char *user_input, *token, *temp, **argv;
	int i, argc, command, user_input_len, command_table_size;

	printbanner();	
	command_table_size = sizeof(command_table) / sizeof(command_table[0]);
	printf("This should print first\n");
	while (1)
	{
		user_input = getline_reader();
		if (user_input != NULL)
		{
			user_input_len = strlen(user_input);
			user_input[user_input_len - 1] = '\0';
		}
		temp = strdup(user_input);

		argc = 0; /* Getting argc */
		token = strtok(user_input, " ");
		while (token != NULL)
		{
			argc++;
			token = strtok(NULL, " ");
		}
		argv = malloc((argc + 1) * sizeof(char *));/* Creating argv */
		token = strtok(temp, " ");
		i = 0;
		while (token != NULL)
		{
			argv[i] = token;
			token = strtok(NULL, " ");/* strtok continues from the previous word */
			i++;
		}
		argv[i] = NULL;
		i = 0;
		command = 0;
		while (i < command_table_size)
		{
			if (strcmp(argv[0], command_table[i].command) == 0)
			{
				if (strcmp(argv[0], "exit") == 0)
				{
					free(argv);
					free(temp);
					free(user_input);
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
		free(temp);
		free(user_input);
	}
	printf("(main) You said to exit\n");

	return (0);
}
