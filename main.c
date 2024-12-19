#include "shell.h"

int main(void)
{
    char *line;
    char **args;

    while (1)
    {
        line = get_line();
        args = parse(line);
        execute(args);
        free(args);
        free(line);
    }
    return (0);
}
