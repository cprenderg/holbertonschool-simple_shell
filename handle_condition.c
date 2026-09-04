#include "main.h"
/**
 * handle_condition - if user input has a specifier handle appropriately
 * @input: what user has entered into stdin
 * @status: last status of shell
 * @history_h: head of history list
 * @head: head of env list
 *
 * Return: 0 on success, 1 if want_exit
 */
int handle_condition(char *input, historylist_t *history_h,
	int *status, envlist_t **head)
{
	size_t i = 0;
	int error = 0;
	char *post_spec, *pre_spec, *post_spec_dup;
	char spec, specifiers[] = "|&;";

	post_spec = _strpbrk(input, specifiers);/* finding where the pipe is*/
	spec = *post_spec;
	if (spec == ';') /* increment once for a ';' otherwise twice*/
		post_spec++;
	else
		post_spec += 2;
	post_spec_dup = _strdup(post_spec);

	while (input[i] != spec) /* find length of string before specifier and dup that part*/
		i++;
	pre_spec = strndup(input, i);

	handle_input(pre_spec, history_h, status, head);
	if (spec == ';')
		error = handle_input(post_spec_dup, history_h, status, head);

	else if (spec == '&' && *status == 0)
		error = handle_input(post_spec_dup, history_h, status, head);

	else if (spec == '|' && *status != 0)
		error = handle_input(post_spec_dup, history_h, status, head);

	free(pre_spec);
	free(post_spec_dup);
	return (error);
}
