#include "main.h"
/**
 * free_list - frees a envlist_t list
 * @head: head of envlist_t list
 *
 * Return: void
 */
void free_env(envlist_t *head)
{
	if (head == NULL)
	{
		return;
	}
	free_env(head->next);
	free(head->name);
	free(head);
}
