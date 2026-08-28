#include "main.h"
int function_search(char **argv)
{
	char *directory, *temp, *token, path[1024];
	extern char **environ;
	int found = 0;
	pid_t pid = -1;
	
	if ((temp = _getenv("PATH")) == NULL)
		return (1);
	directory = malloc(strlen(temp) + 1 * sizeof(char));
	strcpy(directory, temp);
	token = strtok(directory, ":");

	while (token != NULL)
	{
		sprintf(path,"%s/%s", token, argv[0]);
		if (access(path, X_OK) == 0)
		{
			found = 1;
			break;
		}
		token = strtok(NULL, ":");
	}
	free(directory);
	if (found == 1)
		pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		execve(path, argv, environ);
		free(temp);
		_exit(1);
	}
	else if (pid == -1)
	{
		free(temp);
		return (1);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
	}
	free(temp);
	return (0);
}
