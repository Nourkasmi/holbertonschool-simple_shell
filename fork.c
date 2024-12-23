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
    pid_t pid;


    if (args[0] == NULL || !is_command_valid(args[0]))
    {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return;
    }

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

/**
 * is_command_valid - Checks if the command is valid (exists in PATH or as an absolute/relative path)
 * @cmd: The command to check
 * @env: The environment variables
 *
 * Return: 1 if valid, 0 if not
 */
int is_command_valid(char *cmd)
{
    char full_path[1024];
    char *path_env = getenv("PATH");
    char *path_copy = NULL;
    char *token = NULL;

    if (cmd[0] == '/' || cmd[0] == '.')
    {
        return access(cmd, X_OK) == 0;
    }

    
    if (path_env == NULL || strlen(path_env) == 0)
    {
        return 0;
    }

    path_copy = strdup(path_env);
    if (path_copy == NULL)
    {
        perror("strdup");
        return 0;
    }

    token = strtok(path_copy, ":");
    while (token != NULL)
    {
        full_path[0] = '\0';
        strcat(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, cmd);

        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return 1;
        }

        token = strtok(NULL, ":");
    }

    free(path_copy);
    return 0;
}
