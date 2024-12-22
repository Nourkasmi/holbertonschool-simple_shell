#include "shell.h"

/**
 * main - Entry point for the shell program
 * @argc: Argument count (not used)
 * @argv: Argument vector (array of command line arguments, not used)
 * @env: Environment variables for the shell
 *
 * Return: 0 on success, exits on EOF (Ctrl+D)
 */
int main(int argc, char **argv, char **env)
{
char *line = NULL, **args;
(void)argc;
(void)argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");
		line = get_line();
		args = parse_input(line);
		if (args && args[0])
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free(args);
				free(line);
				exit(EXIT_SUCCESS);
			}
			if (strcmp(args[0], "env") == 0)
			{
				int i;

				for (i = 0; env[i]; i++)
					printf("%s\n", env[i]);
			}
			else
			{
				fork_and_execute(args, env);
			}
		}
		free(args);
		free(line);
	}
	return (0);
}
