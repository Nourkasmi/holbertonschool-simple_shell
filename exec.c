#include "shell.h"

void execute_command(char **args, char **env)
{
char full_path[1024];
char *path_env, *path_copy, *token;

	if (!args[0])
		return;
	if (args[0][0] == '/' || args[0][0] == '.')
	{
		if (execve(args[0], args, env) == -1)
			perror("Error executing command");
	}
	else
	{
		path_env = getenv("PATH");
		path_copy = strdup(path_env);
		token = strtok(path_copy, ":");
		while (token)
		{
			sprintf(full_path, "%s/%s", token, args[0]);
			if (access(full_path, X_OK) == 0)
			{
				if (execve(full_path, args, env) == -1)
					perror(args[0]);
				free(path_copy);
				return;
			}
			token = strtok(NULL, ":");
		}
		free(path_copy);
		fprintf(stderr, "%s: command not found\n", args[0]);
	}
}
