#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * main - Main for Built shell
 * @argc: number of arguments
 * @argv: Array of arguments
 * @envp: Array of environment variables
 * Return: Always 0.
 */
int main(int argc, char *argv[], char *envp[])
{
	char **string;
	size_t n = 20, imbt = 0, pt = 4;
	ssize_t num_char;
	char *ptr, *nc;

	if (argc > 1)
		argv[1] = NULL;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		ptr = malloc(sizeof(char) * n);
		num_char = _getline(&ptr, &n, stdin);
		if (num_char == -1)
		{
			free(ptr);
			exit(EXIT_FAILURE);
		}
		if (*ptr != '\n')
		{
			string = chstrtok(ptr);
			if (_strcmp("exit", string[0]) == 0)
				break;
			imbt = checkinbuilt(string[0]);
			nc = filechk(string[0]);
			if (imbt == 0 &&  nc != NULL)
				string[0] = nc;
			pt = pathchk(string[0]);
			if (pt == 1)
				forkexe(string, envp);
			if (nc == NULL && pt == 0 && imbt == 0)
				printf("./shell: No such file or directory\n");
		}
	}
	free(nc);
	free(ptr);
	free(string);
	exit(0);
}
