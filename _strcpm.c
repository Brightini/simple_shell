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
int _strcmp(char *fi, char *sd)
{
	int i = 0, len;

	len = strlen(sd);
	while (fi[i] != '\0')
	{
		if (fi[i] != sd[i])
		{
			return (1);
		}
		i++;
	}
	if (len != i )
		return (1);
	return (0);
}
