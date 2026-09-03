#include "main.h"
/**
 * handle_condition - if user input has a specifier handle appropriately
 * @input: what user has entered into stdin
 * @spec: specifier found
 * @last_status: last status of shell
 *
 * Return: 0 on success, 1 if want_exit
 */
int handle_condition(char *input, historylist_t *history_h, int *last_status, envlist_t **head)
{
	size_t i = 0;
	int error = 0;
	char *post_spec, *pre_spec;
	char spec, specifiers[] = {'|', '&', ';'};

	post_spec = _strpbrk(input, specifiers);/* finding where the pipe is*/
	spec = *post_spec;
	post_spec += 2;
	while(input[i] != spec)
		i++;
	pre_spec = strndup(input, i);
	if (pre_spec)
		pre_spec[strlen(pre_spec)] = '\0';
	if (spec == ';')
	{
		handle_input(pre_spec, history_h, last_status, head);
		handle_input(post_spec, history_h, last_status, head);
	}
	else if (spec == '&')
	{
		if (handle_input(pre_spec, history_h, last_status, head) == 0)
			error = handle_input(post_spec, history_h, last_status, head);
	}
	else if (spec == '|')
	{
		if (handle_input(pre_spec, history_h, last_status, head) == 1)
			error = handle_input(post_spec, history_h, last_status, head);
	}
	free(pre_spec);
	return (error);
}
