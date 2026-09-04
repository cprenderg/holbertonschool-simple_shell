#include "main.h"
/**
 * add_node_env - adds a new node at the beginning of a envlist_t list
 * @head: pointer to a envlist_t structure
 * @str: string for envlist_t->name
 *
 * Return: address of the new element, or NULL if it failed
 */
envlist_t *add_node_env(envlist_t **head, char *str)
{
	char *new_str;
	envlist_t *new_node;

	new_node = malloc(sizeof(envlist_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_str = _strdup(str);
	if (new_str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->name = new_str;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}
