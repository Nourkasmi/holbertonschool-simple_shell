#include "shell.h"

int main(int argc, char **argv, char **env)
{
char *line = NULL, **args;
size_t len = 0;

	(void)argc;
	(void)argv;
	while (1)
	{
		display_prompt();
		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
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
	return (0);
}
