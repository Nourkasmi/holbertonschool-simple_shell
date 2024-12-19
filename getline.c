#include "shell.h"

char *get_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("($) ");
	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		free(line);
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';
	return (line);
}
