#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * _strcmp - Function to compare two string
 * @fi: First string
 * @sd: Second string
 * Return: 0 if true and 1 if false
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
	if (len != i)
		return (1);
	return (0);
}
