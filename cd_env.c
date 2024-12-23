#include "shell.h"

/**
 * handle_cd - Handles the `cd` built-in command
 * @args: The arguments for the command
 *
 * Return: None
 */
void handle_cd(char **args)
{
                if (args[1] == NULL || chdir(args[1]) == -1)
                {
                    perror("cd");
                }

}

/**
 * handle_env - Handles the `env` built-in command
 * @env: The environment variables
 *
 * Return: None
 */
void handle_env(char **env)
{
    int i;

    for (i = 0; env[i]; i++)
        printf("%s\n", env[i]);
}
