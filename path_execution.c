#include "main.h"
/**
 * path_execution - executes a program when the user put enter the path
 * @argv: array of pointers
 * @last_status: the last status variable to store error codes
 * Return: void
 */
int path_execution(char **argv, int *last_status)
{
	int fd, status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		fd = open(argv[0], O_DIRECTORY);
		if (fd != -1)
		{
			close(fd);
			fprintf(stderr, COLOR_RED "Shell V.01: %s: Is a directory\n"RESET, argv[0]);
			exit(126);
		}
		else
		{
			execve(argv[0], argv, environ);
			fprintf(stderr, COLOR_RED "Shell V.01: %s: %s\n"RESET,
				argv[0], strerror(errno));
			_exit(127);
		}
	}
	else if (pid == -1)
	{
		*last_status = 254;
		return (1);
	}
	waitpid(pid, &status, 0);
	*last_status = WEXITSTATUS(status);
	return (*last_status);
}
