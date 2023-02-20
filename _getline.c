#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * _getline - Print "$ " first with the string after it on next line
 * @lineptr: parameter of address holding buffer of string
 * @n: length of string
 * @stream: The stream to receive file;
 * Return: length of input string
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t len = 120, *lenptr = &len;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		perror("Error! wrong parameter or file pointer problem");
		exit(1);
	}
	if (*lineptr == NULL)
	{
		*lineptr = realloc(*lineptr, sizeof(char) * *lenptr);
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
		fgets(*lineptr, *lenptr, stream);
		if (strlen(*lineptr) > (*lenptr - 10))
		{
			*lenptr = *lenptr * 2;
			*lineptr = realloc(*lineptr, strlen(*lineptr));
			if (*lineptr == NULL)
				exit(1);
		}
		else
			if ((*lineptr)[strlen(*lineptr) - 1] == '\n')
			{
				*n = strlen(*lineptr);
				*lineptr[*n] = '\0';
				return (strlen(*lineptr));
			}
	}
	return (0);
}
