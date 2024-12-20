#include "shell.h"

int main(int argc, char **argv, char **env)
{
char *line = NULL, **args;

	(void)argc;
	(void)argv;
	while (1)
	{
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
			fork_and_execute(args, env);
		}
		free(args);
	}
	free(line);
	free(args);
	return (0);
}
