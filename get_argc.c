#include "main.h"
/**
 * get_argc - counts the amount of arguments in the input
 * @user_input: pointer to the input from the user
 *
 * Return: number of arguments in user input
 */
int get_argc(char *user_input)
{
	int argc = 0;
	char *temp, *token;

	if (user_input != NULL)
	{
		temp = _strdup(user_input);
		token = _strtok(temp, " ");
		while (token != NULL)
		{
			argc++;
			token = _strtok(NULL, " ");
		}
		free(temp);
	}
	return (argc);
}

