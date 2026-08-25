#include "main.h"
/**
*readline_reader - reads the standard input
*Return: pointer to string 
*/
char *readline_reader(void)
{
	char *buffer;
	char directory_path[1024];
	size_t buffersize;
	
	getcwd(directory_path, sizeof(directory_path));
	printf("%s", directory_path);
	
	buffer = NULL; // setting to NULL means readline will allocate the size
	buffer = readline("$ ");
	if (buffer == NULL)
	{ //Is true if there was no input to read
		printf("Error no input to read");
		exit;
	}
	add_history(buffer);

	return(buffer);
}
