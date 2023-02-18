#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * main - Main for Built shell
 *
 * Return: Always 0.
 */
int main(void)
{
	char **string;
	size_t n = 20, imbt = 0, pt = 4;
	ssize_t num_char;
	char *ptr, *nc;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 0)
			exit(0);
		printf("#cisfun$ ");
		ptr = malloc(sizeof(char) * n);
		num_char = getline(&ptr, &n, stdin);
		if (num_char == -1)
		{
			free(ptr);
			exit(EXIT_FAILURE);
		}
		if (*ptr != '\n')
		{
			string = chstrtok(ptr);
			if (_strcmp("exit", string[0]) == 0)
				exit(0);
			imbt = checkinbuilt(string[0]);
			nc = filechk(string[0]);
			if (imbt == 0 &&  nc != NULL)
				string[0] = nc;
			pt = pathchk(string[0]);
			if (pt == 1)
				forkexe(string);
			if (nc == NULL && pt == 0 && imbt == 0)
			{
				printf("./shell: No such file or directory\n");
			}
		}
	}
	free(ptr);
	free(string);
	exit(0);
}
