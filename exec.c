#include "shell.h"

/**
 * execute_command - Executes a command by searching in
 * directories listed in PATH
 * @args: An array of command arguments (args[0] is the command)
 * @env: The environment variables to be passed to the command
 *
 * Return: None
 */

void execute_command(char **args, char **env)
{
char full_path[1024];
char *path_env = getenv("PATH");
char *path_copy = strdup(path_env);
char *token = strtok(path_copy, ":");
	if (args[0][0] == '/' || args[0][0] == '.')
	{
		if (execve(args[0], args, env) == -1)
			fprintf(stderr, "%s: 1: %s: not found\n", args[0], args[0]);
	}
	else
	{
		while (token)
		{
			sprintf(full_path, "%s/%s", token, args[0]);
			if (access(full_path, X_OK) == 0)
			{
				if (execve(full_path, args, env) == -1)
					fprintf(stderr, "%s: 1: %s: not found\n", args[0], args[0]);
				free(path_copy);
				return;
			}
			token = strtok(NULL, ":");
		}
		fprintf(stderr, "%s: 1: %s: not found\n", args[0], args[0]);
	}
	free(path_copy);
}
