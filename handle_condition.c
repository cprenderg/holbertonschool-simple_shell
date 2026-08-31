#include "main.h"
/**
 * handle_pipe - if user input has a pipe handle appropriately
 * @user_input: what user has entered into stdin
 *
 * Return: 0 on success, 1 if want_exit
 */
int handle_condition(char *user_input, char spec, int *last_status)
{
	int argc_left, argc_right;
	char **argv_left, **argv_right;
	char *split_point, *left_command, *right_command;

	/* finding where the pipe is*/
	split_point = strchr(user_input, spec);
	
	*split_point = '\0'; /* splits the string with /0 */
	left_command = user_input; /* original string but null terminated where | was */
	right_command = split_point + 2; /* points to string after spec */

	argc_left = get_argc(left_command);
	argc_right = get_argc(right_command);
	argv_left = get_argv(argc_left, left_command);
	argv_right = get_argv(argc_right, right_command);

	if (spec == '&')
	{
		if (function_search(argv_left, last_status) == 1)
			printf("'%s': command not found\n", argv_left[0]);
		if (function_search(argv_right, last_status) == 1)
			printf("'%s': command not found\n", argv_right[0]);
	}
	else if (spec == '|')
	{
		if (function_search(argv_left, last_status) == 1)
		{
			printf("'%s': command not found\n", argv_left[0]);
			if ((function_search(argv_right, last_status)) == 1)
				printf("'%s': command not found\n", argv_right[0]);
		}
	}

	free(argv_left);
	free(argv_right);
	return (0);
}
