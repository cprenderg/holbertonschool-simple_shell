#include "main.h"
int path_execution(char **argv)
{
	int fd;
	extern char **environ;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		fd = open(argv[0], O_DIRECTORY);
		if (fd != -1)
		{
			close(fd);
			fprintf(stderr, "Shell V.01: %s: Is a directory\n", argv[0]);
			exit(126);
		}
		else
		{
			execve(argv[0], argv, environ);
			fprintf(stderr, "Shell V.01: %s: %s\n", argv[0], strerror(errno));
			exit(127);
		}
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
