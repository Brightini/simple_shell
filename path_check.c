#include "shell.h"

/**
 * path_check - check if command path is valid
 *
 * @str: (str) command path
 * Return: 0 if true, otherwise 1
 */
int path_check(char *str)
{
	char *cmp = "/bin/", *ptr, *j;
	int i = 0, p = 0;

	ptr = malloc(sizeof(char) * MAX_COMMANDS);
	if (!ptr)
	{
		free(ptr);
		return (1);
	}
	while (cmp[i] != '\0')
	{
		if (cmp[i] != str[i])
		{
			free(ptr);
			return (1);
		}
		i++;
	}
	while (str[i] != '\0')
		ptr[p] = str[i], p++, i++;

	ptr[p] = '\0';
	j = create_path(ptr);
	if (j)
	{
		free(ptr);
		return (0);
	}
	return (1);
}
