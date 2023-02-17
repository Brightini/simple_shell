#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * checkinbuilt - Funtion 2 chk if inbuilt command to execute\
 it and skip fork
 * @str: string to chect for inbuilt command if present
 * Return: 1 if false and 0 if true
 */
int checkinbuilt(char *str)
{
	char *arr[] = {"cd", "exit", "hello"};
	int i = 0;
	char *username;

	for (i = 0; i < 3; i++)
	{
		if (strcmp(str, arr[i]) == 0)
		{
			break;
		}
		i++;
	}
	switch (i)
	{
	case 0:
		chdir(str);
		return (1);
	case 1:
		printf("bye");
		return (2);
	case 2:
		username = getenv("USER");
		printf("Hello %s\n", username);
		return (1);
	default:
		return (0);
	}
	return (0);
}
