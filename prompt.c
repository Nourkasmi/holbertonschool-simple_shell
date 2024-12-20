#include "shell.h"

void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		printf("($) ");
	fflush(stdout);
}
