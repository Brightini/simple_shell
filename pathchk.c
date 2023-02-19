#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * pathchk - Function to check if the string has the path "/bin/"
 * @str: The string to carryout the check
 * Return: 0 if false and 1 if true that the path is found
 */
int pathchk(char *str)
{
	char *cmp = "/bin/", *ptr, *j;
	int i = 0, p = 0;

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
	if (j != NULL)
	{
		free(ptr);
		return (1);
	}
	return (0);
}
