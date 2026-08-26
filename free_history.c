#include "main.h"
/**
 * free_history - frees a historylist_t list
 * @head: head of history_list_t list
 *
 * Return: void
 */
void free_history(historylist_t *head)
{
	if (head == NULL)
	{
		return;
	}
	if (head->next != NULL)
	{
		free_history(head->next);
	}
	free(head->user_input);
	free(head);
}
