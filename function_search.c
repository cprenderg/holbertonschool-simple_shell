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
	int found = 0, status;
	pid_t pid = -1;

	temp = _getenv("PATH"); 
	if (temp == NULL) /*hardcodes a default path if $PATH doesnt exist*/
		temp = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
	directory = _strdup(temp);
	token = _strtok(directory, ":");
	while (token != NULL)
	{
		sprintf(path, "%s/%s", token, argv[0]); /*writes to the string buffer*/
		if (access(path, X_OK) == 0) /*Checks if the file exists and if it can be executed*/
		{
			found = 1;
			break;
		}
		token = _strtok(NULL, ":");
	}
	free(directory);
	if (found == 1)
		pid = fork();
	else
	{
		*last_status = 127;
		return (127);
	}
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL); /* Reset CTRL + C functionality*/
		execve(path, argv, environ);
		fprintf(stderr, COLOR_RED "./hsh: 1: %s: %s\n"RESET,
			argv[0], strerror(errno)); /*This print and exit only happens if execve fails*/
		_exit(127);
	}
	else if (pid == -1)
	{
		*last_status = 254;
		return (254); 
	}

	waitpid(pid, &status, 0);
	*last_status = WEXITSTATUS(status); /*gets the exit code from the child process*/
	return (*last_status);
}
