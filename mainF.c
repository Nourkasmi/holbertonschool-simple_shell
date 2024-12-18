#include "shell.h" 

int main(void)
{
    char *line = NULL;
    size_t len = 0;        
    ssize_t nread;         

    while (1)
    {
        printf("($) ");
        nread = getline(&line, &len, stdin);

        if (nread == -1) 
        {
            free(line);
            printf("\n");
            break;
        }

        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        if (fork() == 0)
        {

char *args[2];
args [1] = line;
args [2] = NULL;

            if (execve(line, args, NULL) == -1)
                perror("./hsh");
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(NULL);
        }
    }
    return (0);
}
