#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
/**
 * main - Print "$ " first with the string after it on next line
 *
 * Return: Always 0.
 */
int main()
{
	pid_t child_pid;
	int status;
	char **string;
	size_t n = 20;
	ssize_t i = 1, num_char;
	char *ptr;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			i = 0;
			printf("#cisfun$ ");
		}
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
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error: Fork issue");
				return (1);
			}
			if (child_pid == 0)
			{
				if (execve(string[0], string, NULL) == -1)
					printf("./shell: No such file or directory\n");
			}
			else
			{
				if (i == 1)
					exit(0);
				wait(&status);
			}
		}
	}
	exit(0);
}

/**
 * _getline - Print "$ " first with the string after it on next line
 * @lineptr: parameter of address holding buffer of string
 * @n: length of string
 *@stream: The stream to receive file;
 * Return: length of input string.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char str[120];

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		perror("Error! wrong parameter or file pointer problem");
		exit(1);
	}
	if (*lineptr == NULL)
	{
		if ((*lineptr = malloc(sizeof(str))) == NULL)
		{
			perror("Unable to allocate memory");
			exit(1);
		}
	}
	*lineptr[0] = '\0';
	while (fgets(*lineptr, *n, stream))
	{
		if ((*n - strlen(*lineptr)) < sizeof(str))
		{
			*n *= 2;
			if ((*lineptr = realloc(*lineptr, *n)) == NULL)
			{
				perror("Unable to reallocate memory");
				exit(1);
			}
		}
		strcat(*lineptr, str);
		if ((*lineptr)[strlen(*lineptr) - 1] == '\n')
			return (strlen(*lineptr));
	}
	return (0);
}
