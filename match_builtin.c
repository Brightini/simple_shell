#include "shell.h"

/**
 * match_builtin - matches built-in command to its function
 * for exectution
 *
 * @str: built-in command (with argument if any)
 * Return: 0 if it fails
*/
size_t match_builtin(char **str)
{
	int i = 0;

	builtin_t match[] = {
		{"exit", my_exit},
		{"setenv", _setenv},
		{NULL, NULL},
	};
	while (match[i].command)
	{
		if (_strcmp(match[i].command, str[0]) == 0)
			return (match[i].fptr(str));
		i++;
	}
	return (0);
}
