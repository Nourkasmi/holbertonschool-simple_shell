#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "($) "
#define MAX_ARGS 100

int main(void);
char **parse(char *input);
void execute(char **args);
char *get_line(void);

#endif
