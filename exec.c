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
    char *path_env = NULL;
    char *path_copy = NULL;
    char *token = NULL;
    extern char **environ;
    int i; 

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
    for (i= 0; environ[i] != NULL; i++)
    {
        if (strncmp(environ[i], "PATH=", 5) == 0)
        {
            path_env = environ[i] + 5;
            break;
        }
    }

    if (path_env == NULL)
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
    while (token != NULL)
    {

        strcpy(full_path, token);    
        strcat(full_path, "/");
        strcat(full_path, args[0]);   


        if (access(full_path, X_OK) == 0)
        {
            execve(full_path, args, env);
            perror(args[0]);
            break;
        }

        token = strtok(NULL, ":");
    }

    free(path_copy);

    if (token == NULL)
        fprintf(stderr, "%s: command not found\n", args[0]);
}
