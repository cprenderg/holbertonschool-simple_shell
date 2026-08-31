#include "main.h"
int function_search(char **argv, int *last_status)
{
	char *directory, *temp, *token, path[1024];
	extern char **environ;
	int found = 0;
	pid_t pid = -1;
	
	if ((temp = _getenv2("PATH")) == NULL)
		temp = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
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
		_exit(1);
	}
	else if (pid == -1)
	{
		return (1);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
		*last_status = WEXITSTATUS(status);
	}
	return (0);
}
