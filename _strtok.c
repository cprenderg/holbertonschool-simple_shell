#include "main.h"
/**
 * _strtok - tokenises a string at specifier
 * @str: string to tokenise
 * @spec: specifier to tokenise at
 *
 * Return: The next token in the string
 */
char *_strtok(char *str, char *spec)
{
	static char *next_token; /* need to track where next token is between calls */
	char *token;
	int i, j;

	if (str != NULL)
		token = str;
	else
		token = next_token;
	if (token == NULL)
		return (NULL);

	i = 0;
	while (token[i])
	{
		j = 0;
		while (spec[j] != '\0')
		{
			if (token[i] == spec[j]) /* finds specifier */
			{
				while (token[i] == spec[j]) /* sets all specifier in a row to '\0' */
				{
					token[i] = '\0';
					i++;
				}
				next_token = token + i; /* sets next_token for subsequent call */
				return (token);
			}
			j++;
		}
		i++;
	}
	next_token = NULL;
	return (token);
}
