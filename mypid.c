#include "shell.h"

void print_pid(void)
{
	printf("PID: %d\n", getpid());
}

void print_ppid(void)
{
	printf("PPID: %d\n", getppid());
}
