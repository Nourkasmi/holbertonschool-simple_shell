#include "shell.h"

char **parse(char *line)
{
char **args = malloc(MAX_ARGS * sizeof(char *));
char *token;
int i = 0;
if (args == NULL)
{
perror("malloc");
return (NULL);
}
token = strtok(line, " ");
while (token != NULL && i < MAX_ARGS - 1)
{
args[i] = token;
token = strtok(NULL, " ");
i++;
}
args[i] = NULL;
return (args);
}
