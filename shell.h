#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


#define PROMPT "($) "
#define MAX_ARGS 100

char **parse_input(char *line);
void fork_and_execute(char **args, char **env);
void execute_command(char **args, char **env);
char *get_line(void);
void handle_cd(char **args);
void handle_env(char **env);

#endif
