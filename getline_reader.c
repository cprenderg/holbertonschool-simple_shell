#include "main.h"
/**
 * getline_reader - reads the standard input
 * Return: pointer to string
 */
char *getline_reader()
{
	char *buffer;
	size_t buffersize, buffer_len;

	buffer = NULL; /* setting to NULL means getline will allocate the size*/
	if (getline(&buffer, &buffersize, stdin) == -1)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}

	buffer_len = strlen(buffer);

	if (buffer_len > 1)
		buffer[buffer_len - 1] = '\0';
	else
		buffer[buffer_len] = '\0';
	return (buffer);
}
