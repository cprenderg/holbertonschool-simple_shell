#include "main.h"
/**
 * _setenv - sets an environment variable
 * @argv: pointer to array of strings of user input
 * @head: pointer to head of envplist_t
 *
 * Return: 0 on success, 1 on failure
 */
int _setenv(char **argv, envlist_t **head, char *user_input, int *status)
{
	char *old_value, *new_value, *temp, *cpy_input, **argv2;
	int i, j, var_len, name_len;
	
	if (argv[1] == NULL)
		return (1);

	if (strcmp(argv[1], "env") == 0)
	{
		argv2 = argv;
		argv2++;
		return (function_search(argv2, status));
	}
	if (argv[2] == NULL)
		return (1);

    old_value = _getenv(argv[1]);
	i = 0;
	if (old_value == NULL)
	{
		while (environ[i] != NULL)
		{
			i++;
		}
		environ[i + 1] = NULL;
	}
	else
	{
		name_len = strlen(argv[1]);
		while (environ[i] != NULL)
		{
			if (strncmp(argv[1], environ[i], name_len) == 0 && environ[i][name_len] == '=')
			{
				break;
			}
			i++;
		}
	}

	/* making the new env */
	j = 0;
	var_len = 0;
	while (argv[j] != NULL) /*will need this if more than argv[2]*/
	{
		var_len += strlen(argv[j]) + 1;
		j++;
	}
	cpy_input = temp = _strdup(user_input);
	
	while (*temp != '\0' && *temp != ' ')
	{
		temp++;
	}
	temp++;
	while (*temp != '\0' && *temp != ' ')
	{
		temp++;
	}

	new_value = malloc(var_len + 1);
	snprintf(new_value, var_len + 1, "%s=%s", argv[1], temp + 1);

	environ[i] = add_node_env(head, new_value)->name;
	free(new_value);
	free(cpy_input);
    return (0);
}
