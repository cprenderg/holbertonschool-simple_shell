#include "main.h"
/**
 * get_argv - turns user input into an array of strings
 * @argc: amount of arguments
 * @user_input: user input
 *
 * Return: array of pointers to strings containing user input
 */
char **get_argv(int argc, char *user_input)
{
	char **argv;
	char *token;
	int i = 0;

	argv = malloc((argc + 1) * sizeof(char *));
	token = strtok(user_input, " ");
	while (token != NULL)
	{
		argv[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;
	return(argv);
}
