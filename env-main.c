#include "shell.h"

char **copy_env(char **env)
{
int i, count = 0;
char **env_copy;

	while (env[count])
		count++;
	env_copy = malloc((count + 1) * sizeof(char *));
	if (!env_copy)
	{
		perror("malloc");
		return (NULL);
	}
	for (i = 0; i < count; i++)
	{
		env_copy[i] = strdup(env[i]);
		if (!env_copy[i])
		{
			perror("strdup");
			while (i--)
				free(env_copy[i]);
			free(env_copy);
			return (NULL);
		}
	}
	env_copy[count] = NULL;
	return (env_copy);
}
void free_env(char **env)
{
int i = 0;
	if (!env)
		return;
	while (env[i])
		free(env[i++]);
	free(env);
}
