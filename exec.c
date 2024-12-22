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
char *path_env = NULL;
char *path_copy;
char *token;
int i;
	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			path_env = env[i] + 5;
			break;
	}}
	if (path_env == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable is not set.\n");
		return;
	}
	if (strlen(path_env) == 0)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return;
	}
	path_copy = strdup(path_env);
	if (path_copy == NULL)
	{
		perror("strdup");
		return;
	}
	token = strtok(path_copy, ":");
	if (args[0][0] == '/' || args[0][0] == '.')
	{
		if (execve(args[0], args, env) == -1)
		{
			perror(args[0]);
		}}
	else
	{
		while (token)
		{
			strcpy(full_path, token);
			strcat(full_path, "/");
			strcat(full_path, args[0]);
			if (access(full_path, X_OK) == 0)
			{
				if (execve(full_path, args, env) == -1)
				{
					perror(args[0]);
				}
				free(path_copy);
				return;
			}
			token = strtok(NULL, ":");
		}
		fprintf(stderr, "%s: command not found\n", args[0]);
	}
	free(path_copy);
}
