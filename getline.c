#include "shell.h"

char *get_line(void)
{
char *line = NULL;
size_t len = 0;
	if (isatty(STDIN_FILENO))
		printf("($) ");
	fflush(stdout);
	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';
	if (strcmp(line, "exit") == 0)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}
