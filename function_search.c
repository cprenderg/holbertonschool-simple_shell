#include "main.h"
int function_search(char **argv)
{
	char *directory;
	char *temp;
	char path[1024];
	pid_t pid;
	
	if ((temp = getenv("PATH")) == NULL)
		return (1);
	directory = malloc(strlen(temp) + 1 * sizeof(char));
	strcpy(directory, temp);
	directory = strtok(directory, ":");

	while (directory != NULL)
	{
		sprintf(path,"%s/%s", directory, argv[0]);
		if (access(path, X_OK) == 0)
			break;
		directory = strtok(NULL, ":");
	}
	pid = fork();
	if (pid == 0)
	{
		execv(path, argv);
		return (1);
	}
	else if (pid == -1)
		return (1);
	else
	{
		int status;
		waitpid(pid, &status, 0);
	}
	return (0);
}