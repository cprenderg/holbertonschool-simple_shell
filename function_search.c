#include "main.h"
/**
 * function_search - attempts to execute a user command
 * @argv: pointer to array of strings of user input
 * @last_status: last status of shell
 *
 * Return: Exit status of child
 */
int function_search(char **argv, int *last_status)
{
	char *directory, *temp, *token, path[1024];
	int found = 0;
	pid_t pid = -1;
	int status;

	temp = _getenv("PATH");
	if (temp == NULL)
		temp = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
	directory = _strdup(temp);
	token = _strtok(directory, ":");
	while (token != NULL)
	{
		sprintf(path, "%s/%s", token, argv[0]);
		if (access(path, X_OK) == 0)
		{
			found = 1;
			break;
		}
		token = _strtok(NULL, ":");
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
		waitpid(pid, &status, 0);
		*last_status = WEXITSTATUS(status);
	}
	return (0);
}
