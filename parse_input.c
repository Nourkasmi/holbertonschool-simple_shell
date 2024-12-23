#include "shell.h"

/**
 * parse_input - Parses input string into separate arguments
 * @input: A string containing the user input to be parsed
 *
 * Return: A pointer to an array of strings (arguments)
 */
char **parse_input(char *input)
{
char **args = malloc(MAX_ARGS * sizeof(char *));
char *token;
int i = 0;

if (!args)
{
perror("malloc");
exit(EXIT_FAILURE);
}
token = strtok(input, " ");
if (token == NULL)
{
free(args);
return (NULL);
}
while (token != NULL && i < MAX_ARGS - 1)
{
args[i] = token;
token = strtok(NULL, " ");
i++;
}
args[i] = NULL;
return (args);
}
