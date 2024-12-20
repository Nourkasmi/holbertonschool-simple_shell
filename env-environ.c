#include "shell.h"

/**
 * env_environ - Prints the environment variables.
 */
void env_environ(void)
{
extern char **environ;
char **env = environ;
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
