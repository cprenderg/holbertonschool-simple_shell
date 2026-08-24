#include "main.h"
/**
*line_reader - reads the standard input
*Return: pointer to string 
*/
char *line_reader(void)
{
	char *buffer;
	char directory_path[1024];
	size_t buffersize;
	
	getcwd(directory_path, sizeof(directory_path));
	printf("%s$ ", directory_path);

	buffer = NULL; // setting to NULL means getline will allocate the size
	if (getline(&buffer, &buffersize, stdin) == -1)
	{
		if (feof(stdin)) //Is true if there was no input to read
			printf("Error no input to read");

		else //any other fail
			printf("Getline failed");

		free(buffer);
		buffer = NULL;
	}
	return(buffer);
}
