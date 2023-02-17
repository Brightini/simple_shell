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
int pathchk(char *str)
{
	char *cmp = "/bin/", *ptr;
	int i = 0, p = 0, j;

	ptr = malloc(sizeof(char) * 50);
	if (ptr == NULL)
		return (0);
	while (cmp[i] != '\0')
	{
		if (cmp[i] != str[i])
		{
			free(ptr);
			return (0);
		}
		i++;
	}
	while (str[i] != '\0')
	{
		ptr[p] = str[i];
		p++;
		i++;
	}
	ptr[p] = '\0';
	j = filechk(ptr);
	if (j == 1)
	{
		free(ptr);
		return (1);
	}
	return (0);
}
