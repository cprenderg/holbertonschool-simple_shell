#include "main.h"
/**
* _strpbrk - remake of the strpbrk function
* @string: the string to search
* @specifiers: the character to search for
* Return: pointer to first occurence in the string
*/ 
char *_strpbrk(char *string, char *specifiers)
{
	int i, j;

	i = 0;
	while (string[i] != '\0')
	{
		j = 0;
		while (specifiers[j] != '\0')
		{
			if (string[i] == specifiers[j])
				return (string += i);
			j++;
		}
		i++;
	}
	return (NULL);
}
