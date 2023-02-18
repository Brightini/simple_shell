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
char *filechk(char *str)
{
	int i = 0, n = 0;
	char *temp, c, *cats;
	FILE *ptr;

	temp = malloc(sizeof(char) * 50);
	if (temp == NULL)
		return (NULL);

	ptr = fopen("file.txt", "r");
	if (ptr == NULL)
	{
		perror("file open failed");
		free(temp);
		return (NULL);
	}
	while (!feof(ptr))
	{
		c = fgetc(ptr);
		temp[n] = c;
		if (c == '\n')
		{
			temp[n] = '\0';
			if (_strcmp(temp, str) == 0)
			{
				cats = _strcat("/bin/", str);
				free(temp);
				fclose(ptr);
				return (cats);
			}
			n = -1;
		}
		n = n + 1;
		i++;
	}
	temp[n] = '\0';
	if (_strcmp(temp, str) == 0)
	{
		cats = _strcat("/bin/", str);
		free(temp);
		fclose(ptr);
		return (cats);
	}
	free(temp);
	fclose(ptr);
	return (NULL);
}
