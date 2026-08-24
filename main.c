#include "main.h"
int main()
{
	char user_input[11];
	int user_input_len;
	char exit[] = "exit";
	int command_table_size;
	int i;

	static const command_t command_table[] = {
		{"exit", exit_func},
		{"ls", ls_func}
	};
	command_table_size = sizeof(command_table) / sizeof(command_table[0]);

	while (1)
	{
		printf("WANT INPUT\n");
		scanf("%10s", user_input);

		user_input_len = 0;
		while (user_input[user_input_len] != '\0')
		{
			user_input_len++;
		}
		i = 0;
		while (i < command_table_size)
		{
			if (strcmp(user_input, command_table[i].command) == 0)
				{
					command_table[i].function();
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
	}
	printf("You said to exit\n");
	return (0);
}
