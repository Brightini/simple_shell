#include "shell.h"

/**
 * file_check - check if command exists and then
 * constructs a path to the command.
 *
 * @str: string to apply the check
 * Return: path to command or NULL if command is not found
 */
char *create_path(char *str)
{
	DIR *dir = opendir("/bin/");
	char *temp, *path;
	struct dirent *entry;

	if (!dir)
		return (NULL);
	entry = readdir(dir);
	while (entry)
	{
		temp = entry->d_name;
		if (_strcmp(temp, str) == 0)
		{
			path = _strcat("/bin/", str); /* construct command path */
			closedir(dir);
			return (path);
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}
