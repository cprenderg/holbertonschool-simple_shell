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
	char *temp;
	int i = 0;

	argv = malloc((argc + 1) * sizeof(char *));
	temp = strdup(user_input);
	token = strtok(temp, " ");
	while (token != NULL)
	{
		argv[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;
	return(argv);
}
