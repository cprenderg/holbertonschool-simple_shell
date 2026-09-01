#include "main.h"
/**
 * history_func - keeps a linked list of all user input
 * @user_input: user input to stdin
 * @head: head of list
 *
 * Return: pointer to head of list
 */
historylist_t *history_func(char *user_input, historylist_t *head)
{
	char *new_input;
	historylist_t *new_node;

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_input = strdup(user_input);
	if (new_input == NULL)
	{
		free(new_node);
		return (NULL);
	}
	if (head == NULL)
	{
		new_node->id = 0;
	}
	else
	{
		new_node->id = head->id + 1;
	}
	new_node->user_input = new_input;
	new_node->prev = NULL;
	new_node->next = head;
	if (head != NULL)
	{
		head->prev = new_node;
	}
	head = new_node;
	return (new_node);
}

