#include "main.h"

/**
*getline_reader - reads the standard input
*Return: pointer to string 
*/
char *getline_reader(historylist_t *history_head)
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
	if (buffer[0] == '\n')
		return (NULL);

	buffer_len = strlen(buffer);
	buffer[buffer_len - 1] = '\0';

	if (buffer[0] == '/')
		path_execution(buffer);

	if (strcmp(buffer, "history") == 0)
	{
		print_history(history_head);
		printf("history\n");
	}

	return(buffer);
}
