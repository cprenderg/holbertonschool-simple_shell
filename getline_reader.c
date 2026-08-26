#include "main.h"

/**
*getline_reader - reads the standard input
*Return: pointer to string 
*/
char *getline_reader(void)
{
	char *buffer;
	size_t buffersize, buffer_len;

	buffer = NULL; /* setting to NULL means getline will allocate the size*/
	if (getline(&buffer, &buffersize, stdin) == -1)
	{	
		if (feof(stdin)) /*Is true if there was no input to read*/
			printf("[EOF] Exiting..\n");

		else /*any other fail*/
			printf("Getline failed");

		free(buffer);
		buffer = NULL;
		exit(2);
	}
	printf("it gets here1\n");
	buffer_len = strlen(buffer);
	buffer[buffer_len - 1] = '\0';
	if (buffer[0] == '/')
	{
		path_execution(buffer);
		return (NULL);
	}
	return(buffer);
}
