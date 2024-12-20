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


void display_prompt(void);
char **parse_input(char *line);
void fork_and_execute(char **args, char **env);
void execute_command(char **args, char **env);
void print_pid(void);
void print_ppid(void);
char **copy_env(char **env);
void free_env(char **env);
void env_environ(void);

#endif
