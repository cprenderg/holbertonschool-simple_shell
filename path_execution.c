#include "main.h"
int path_execution(char *path)
{
	int argc,fd;
	char **argv;
	extern char **environ;
	pid_t pid;

	argc = get_argc(path);/* Getting argc */
	argv = get_argv(argc, path);/* Creating argv */

	pid = fork();
	if (pid == 0)
	{
		fd = open(path, O_DIRECTORY);
		if (fd != -1)
		{
			close(fd);
			fprintf(stderr, "Shell V.01: %s: Is a directory\n", path);
			exit(126);
		}
		else
		{
			execve(argv[0], argv, environ);
			fprintf(stderr, "Shell V.01: %s: %s\n", path, strerror(errno));
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