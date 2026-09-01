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
	static char *next_token;
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
			if (token[i] == spec[j])
			{
				while (token[i] == spec[j])
				{
					token[i] = '\0';
					i++;
				}
				next_token = token + i;
				return (token);
			}
			j++;
		}
		i++;
	}
	next_token = NULL;
	return (token);
}
