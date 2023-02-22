#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int lmstr(char *str);
/*
int main()
{
	char *ptr;
	size_t n = 20, i;

	ptr = malloc(sizeof(char) * n);
	i = _getline(&ptr, &n, stdin);
	printf("%s %ld", ptr, n);
	return (0);
}
*/

/**
 * _getline - Print "$ " first with the string after it on next line
 * @lineptr: parameter of address holding buffer of string
 * @n: length of string
 * @stream: The stream to receive file;
 * Return: length of input string
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t len = 120, *lenptr = &len, h;

	if (!(isatty(STDIN_FILENO)))
		printf("\n");
	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		perror("Error! wrong parameter or file pointer problem");
		exit(1);
	}
	if (*lineptr == NULL)
	{
		*lineptr = malloc(sizeof(char) * (*lenptr));
		if (*lineptr == NULL)
		{
			perror("Unable to allocate memory");
			exit(1);
		}
	}
	else
		*lineptr = realloc(*lineptr, *lenptr);
	while (1)
	{
		*lineptr = fgets(*lineptr, *lenptr, stream);
		h = lmstr(*lineptr);
		if (h > (*lenptr - 10))
		{
			*lenptr = (*lenptr) * 2;
			*lineptr = realloc(*lineptr, *lenptr);
			if (*lineptr == NULL)
				exit(1);
		}
		if (h < (*lenptr - 10))
			break;
	}
	if (h < (*lenptr - 10))
	{
		*lineptr = realloc(*lineptr, h + 1);
		if (*lineptr == NULL)
			exit (0);
		/*	*lineptr = fgets(*lineptr, (h + 1), stream);*/
		*n = lmstr(*lineptr);
		return (1);
	}
	return (-1);
}
/**
 * _getline - Print "$ " first with the string after it on next l\ine
 * @lineptr: parameter of address holding buffer of string
 * @n: length of string
 * @stream: The stream to receive file;
 * Return: length of input string
 */
int lmstr(char *str)
{
	int i = 0;

	while (str[i] != '\n')
	{
		i++;
	}
	i++;
	return (i);
}
