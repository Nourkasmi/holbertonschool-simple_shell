#include "shell.h"

/**
 * get_line - Reads a line of input from the user
 *
 * Return: A string containing the input entered by the user
 */

char *get_line(void)
{
char *line = NULL;
size_t len = 0;
	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';
	return (line);
}
