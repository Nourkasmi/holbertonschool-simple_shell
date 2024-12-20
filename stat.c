#include "shell.h"

void file_stat(const char *filename)
{
struct stat st;

	if (stat(filename, &st) == -1)
	{
		perror(filename);
		return;
	}
	printf("File: %s\nSize: %ld bytes\n", filename, st.st_size);
}
