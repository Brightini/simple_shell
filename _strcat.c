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
char *_strcat(char *des, char *src)
{
	int a, b, c, i = 0, j = 0;
	char *ptr, *mal;

	a = strlen(des);
	b = strlen(src);
	c = a + b + 1;
	mal = malloc(sizeof(char) * c);
	if (mal == NULL)
		return (NULL);
	for (i = 0; i < a; i++)
	{
		mal[i] = des[i];
	}
	while (j < b)
	{
		mal[i] = src[j];
		i++;
		j++;
	}
	mal[i] = '\0';
	ptr = mal;
	return (ptr);
}
