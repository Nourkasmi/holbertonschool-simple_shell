#include "shell.h"

/**
 * fork_and_execute - Creates a child process to execute a command
 * @args: An array of command arguments (args[0] is the command)
 * @env: The environment variables to be passed to the command
 *
 * Return: None
 */
void fork_and_execute(char **args, char **env)
{
pid_t pid = fork();
int status;
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
		waitpid(pid, &status, 0);
	}
}
