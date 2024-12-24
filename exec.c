#include "shell.h"

/**
 * execute_command - Executes a command by searching in
 * directories listed in PATH or using an absolute/relative path
 * @args: An array of command arguments (args[0] is the command)
 * @env: The environment variables to be passed to the command
 *
 * Return: None
 */
void execute_command(char **args, char **env)
{
	char full_path[1024];
    char *path_env = getenv("PATH");
    char *path_copy = NULL;
    char *token = NULL;
    if (args[0] == NULL)
        return;
    if (args[0][0] == '/' || args[0][0] == '.')
    {
        if (access(args[0], X_OK) == 0)
        {
            execve(args[0], args, env);
            perror(args[0]);
        }
        else
        {
            fprintf(stderr, "%s: command not found\n", args[0]);
        }
        return;
    }
    if (path_env == NULL || strlen(path_env) == 0)
    {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return;
    }
    path_copy = strdup(path_env);
    if (path_copy == NULL)
    {
        perror("strdup error");
        return;
    }
    token = strtok(path_copy, ":");
    while (token != NULL)
    {
        size_t token_len = strlen(token);
        size_t arg_len = strlen(args[0]);
        if (token_len + 1 + arg_len < sizeof(full_path))
        {
            strncpy(full_path, token, sizeof(full_path) - 1);
            full_path[sizeof(full_path) - 1] = '\0';
            strncat(full_path, "/", sizeof(full_path) - strlen(full_path) - 1);
            strncat(full_path, args[0], sizeof(full_path) - strlen(full_path) - 1);

            if (access(full_path, X_OK) == 0)
            {
                execve(full_path, args, env);
                perror(args[0]);
                break;
            }
        }
        token = strtok(NULL, ":");
    }
    free(path_copy);
    if (token == NULL)
    fprintf(stderr, "%s: command not found\n", args[0]);
}