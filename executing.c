#include "shell.h"

void execute(char **args)
{
    if (args[0] == NULL)
        return;
    if (fork() == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("./hsh");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(NULL);
    }
    printf("\n");
}
