#include "main.h"
/**
 * print_history - prints the history list from tail to head
 * @head: pointer to head of history list
 *
 * Return: void
 */
void print_history(historylist_t *head)
{
	historylist_t *print_head;

	print_head = head;
	while (print_head->next != NULL)
	{
		print_head = print_head->next;
	}
	while (print_head != NULL)
	{
		printf("%d %s", print_head->id, print_head->user_input);
		print_head = print_head->prev;
	}
}
