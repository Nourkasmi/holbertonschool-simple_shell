#include "shell.h"


void execute(char **args)
{
    pid_t pid;  
    char full_path[1024];  
    char *path_env;
    char *path_copy;
    char *token;

    if (args[0] == NULL)
        return;

    
    if (strcmp(args[0], "cd") == 0)
    {
        if (args[1] == NULL)
        {
            fprintf(stderr, "cd: expected argument\n");
        }
        else
        {
            if (chdir(args[1]) != 0)
            {
                perror("cd");
            }
        }
        return;
    }

    pid = fork();  

    if (pid == -1)
    {
        perror("fork");
        return;
    }

    if (pid == 0) 
    {
        
        if (args[0][0] == '/' || args[0][0] == '.')
        {
            
            if (execve(args[0], args, NULL) == -1)
            {
                perror("./hsh");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            
            path_env = getenv("PATH");
            path_copy = strdup(path_env);
            token = strtok(path_copy, ":");

            while (token != NULL)
            {
                snprintf(full_path, sizeof(full_path), "%s/%s", token, args[0]);
                if (access(full_path, X_OK) == 0)
                {
                    if (execve(full_path, args, NULL) == -1)
                    {
                        perror("./hsh");
                        exit(EXIT_FAILURE);
                    }
                    break;
                }
                token = strtok(NULL, ":");
            }

          
            fprintf(stderr, "./hsh: command not found: %s\n", args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else 
    {
        wait(NULL); 
    }
}


