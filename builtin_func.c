#include "shell.h"

/**
 * my_exit - cause normal process termination
 *
 * @str: command received from terminal
 * Return: 0 if exit command is not found
*/
size_t my_exit(char **str)
{
	if (!str[1])
		exit(EXIT_SUCCESS);
	else
		{
			if (_atoi(str[1]) == 0)
				return (0);
			exit(_atoi(str[1]));
		}
	return (0);
}

/**
 * _setenv - change or add an environment variable
 *
 * @str: array of strings containing variable name and value
 * Return: 0 on failure
*/
size_t _setenv(char **str)
{
	int i = 0;
	char *name;
	char *value;

	for (; str[i]; i++)
		;
	if (i == 3)
	{
		name = str[1];
		value = str[2];


	}
	return (0);
}
