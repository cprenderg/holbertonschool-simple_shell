#include "main.h"
static const command_t command_table[] = {
		{"exit", exit_func},
		{"cd", cd_func}
	};
int main(void)
{
	char *user_input, **argv;
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
		argc = get_argc(user_input);/* Getting argc */
		argv = get_argv(argc, user_input);/* Creating argv */
		i = 0;
		command = 0;
		while (i < command_table_size)
		{
			if (strcmp(argv[0], command_table[i].command) == 0)
			{
				if (strcmp(argv[0], "exit") == 0)
				{
					free(argv);
					free(user_input);
					exit (0); /* felix please fix this*/
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
	}
	return (0);
}
