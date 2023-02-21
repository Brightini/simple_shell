#include "main.h"

/**
 * pathchk - check if command path is valid
 *
 * @str: (str) command path
 * Return: 0 if false, otherwise 1
 */
int path_check(char *str)
{
	char *cmp = "/bin/", *ptr, *j;
	int i = 0, p = 0;

	ptr = malloc(sizeof(char) * MAX_COMMANDS);
	if (!ptr)
	{
		free (ptr);
		return (0);
	}
	while (cmp[i] != '\0')
	{
		if (cmp[i] != str[i])
		{
			free (ptr);
			return (0);
		}
		i++;
	}
	while (str[i] != '\0')
		ptr[p] = str[i], p++, i++;

	ptr[p] = '\0';
	j = create_path(ptr);
	if (j)
	{
		free (ptr);
		return (1);
	}
	return (0);
}
