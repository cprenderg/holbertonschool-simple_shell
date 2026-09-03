#include "main.h"
/**
 * find_pos - finds where variable to be changed is
 * @argv: array of pointers to user input strings
 *
 * Return: position of variable to change or set
 */
int find_pos(char **argv)
{
	char *old_value;
	int i, name_len;

	old_value = _getenv(argv[1]);
	i = 0;
	if (old_value == NULL) /* finding place for new variable */
	{
		while (environ[i] != NULL)
			i++;
		environ[i + 1] = NULL;
	}
	else /* finding old variable in env */
	{
		name_len = strlen(argv[1]);
		while (environ[i] != NULL)
		{
			if (strncmp(argv[1], environ[i], name_len) == 0 &&
			environ[i][name_len] == '=')
				break;
			i++;
		}
	}
	return (i);
}
/**
 * _setenv - sets an environment variable
 * @argv: pointer to array of strings of user input
 * @head: pointer to head of envplist_t
 * @user_input: user input as a string
 * @status: status of shell
 *
 * Return: 0 on success, 1 on failure
 */
int _setenv(char **argv, envlist_t **head, char *user_input, int *status)
{
	char *new_value, *temp, *cpy_input, **argv2;
	int j, k, var_len, var_pos;

	if (argv[1] == NULL)
		return (1);
	if (strcmp(argv[1], "env") == 0) /* prints env if only given env */
	{
		argv2 = argv;
		argv2++;
		return (function_search(argv2, status));
	}
	if (argv[2] == NULL)
		return (1);

	var_pos = find_pos(argv);
	j = 0;
	var_len = 0;
	while (argv[j] != NULL) /* finding memory needed for new env */
	{
		var_len += strlen(argv[j]) + 1;
		j++;
	}
	cpy_input = temp = _strdup(user_input);
	k = 0;
	while (k != 2) /* Setting pointer in user_input to argv[2] */
	{
		while (*temp != '\0' && *temp != ' ')
			temp++;
		temp++;
		k++;
	}
	new_value = malloc(var_len + 1);
	snprintf(new_value, var_len + 1, "%s=%s", argv[1], temp);
	/* Adds a node into envlist and sets env to that so it can be freed on exit */
	environ[var_pos] = add_node_env(head, new_value)->name;
	free(new_value);
	free(cpy_input);
	return (0);
}
