#include "main.h"
/**
 * _strdup - duplicates a string dynamically
 * @str: string to duplicate
 *
 * Return: Pointer to duplicated string
 */
char *_strdup(char *str)
{
	int len;
	char *dup;

	if (str == NULL)
		return (NULL);
	len = strlen(str);
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	strcpy(dup, str);
	return (dup);
}
