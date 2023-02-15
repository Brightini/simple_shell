#include <sys/wait.h>
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
/**
 * chstrtok - Print "$ " first ine
 * @str: string parameter
 * Return: Array of string
 */
char **chstrtok(char *str)
{
	char **arst;
	int i = 0;

	if ((arst = malloc(8 * sizeof(char *))) == NULL)
	{
		perror("cant allocate space");
		exit(1);
	}
	arst[i] = strtok(str, " ");
	while (arst[i] != NULL)
	{
		i++;
		arst[i] = strtok(NULL, " ");
	}
	return (arst);
}
