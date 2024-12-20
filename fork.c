#include "shell.h"

void fork_and_execute(char **args, char **env)
{
pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		execute_command(args, env);
		_exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
