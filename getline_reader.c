#include "main.h"
/**
*getline_reader - reads the standard input
*Return: pointer to string 
*/
char *getline_reader(void)
{
	char *buffer;
	size_t buffersize;
	
	buffer = NULL; /* setting to NULL means getline will allocate the size*/
	if (getline(&buffer, &buffersize, stdin) == -1)
	{
		if (feof(stdin)) /*Is true if there was no input to read*/
			printf("Error no input to read");

		else /*any other fail*/
			printf("Getline failed");

		free(buffer);
		buffer = NULL;
	}
	return(buffer);
}
