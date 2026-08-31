#include "main.h"

/**
*getline_reader - reads the standard input
*Return: pointer to string 
*/
char *getline_reader()
{
	char *buffer, **argv;
	size_t buffersize, buffer_len;
	int argc;

	buffer = NULL; /* setting to NULL means getline will allocate the size*/
	if (getline(&buffer, &buffersize, stdin) == -1)
	{	
		free(buffer);
		buffer = NULL;
		exit(0);
	}
	if (buffer[0] == '\n')
		return (NULL);

	buffer_len = strlen(buffer);
	buffer[buffer_len - 1] = '\0';

	argc = get_argc(buffer);
	argv = get_argv(argc, buffer);

	if (strchr(argv[0], '/') != NULL)
		path_execution(argv[0]);

	return(buffer);
}
