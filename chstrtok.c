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
	char **arst, *pars;
	int i = 0, j = 0;

	if ((arst = malloc(8 * sizeof(char *))) == NULL)
	{
		perror("cant allocate space");
		exit(1);
	}
	pars = strtok(str, " ");
	while (pars != NULL)
	{
		while (pars[j])
		{
			if (pars[j] == '\n')
				pars[j] = '\0';
			j++;
		}
		arst[i] = pars;
		i++;
		j = 0;
		pars = strtok(NULL, " ");
	}
	arst[i] = NULL;
	return (arst);
}
