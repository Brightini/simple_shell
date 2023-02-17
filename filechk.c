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
int filechk(char *str)
{
	int i = 0, n = 0;
	char *temp, c;
	FILE *ptr;

	temp = malloc(sizeof(char) * 50);
	if (temp == NULL)
		return (0);

	ptr = fopen("file.txt", "r");
	if (ptr == NULL)
	{
		perror("file open failed");
		free(temp);
		return (0);
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
				free(temp);
				fclose(ptr);
				return (1);
			}
			n = -1;
		}
		n = n + 1;
		i++;
	}
	temp[n] = '\0';
	if (_strcmp(temp, str) == 0)
	{
		free(temp);
		fclose(ptr);
		return (1);
	}
	free(temp);
	fclose(ptr);
	return (0);
}
