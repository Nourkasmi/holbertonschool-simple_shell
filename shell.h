#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define PROMPT "($) "
#define MAX_ARGS 100

char **parse_input(char *line);
void fork_and_execute(char **args, char **env);
void execute_command(char **args, char **env);
char *get_line(void);

#endif
