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
	size_t n = 20, imbt = 0;
	ssize_t num_char;
	char *ptr;

	while (1)
	{
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
			imbt = checkinbuilt(string[0]);
			if (imbt == 0)
				forkexe(string);
			else if (imbt == 2)
				continue;
		}
	}
	free(ptr);
	free(string);
	exit(0);
}
