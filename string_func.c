#include "shell.h"

/**
 * _strlen - computes the length of a string
 * excluding null byte
 *
 * @s: pointer to string
 * Return: returns the length of a string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _strcspn - finds the index where @c is located in @str
 * @str: string
 * @c: character to be checked
 * Return: index position of @c or
 * total number of characters if @c is not found
*/
size_t _strcspn(const char *str, char c)
{
	size_t i = 0;

	for (; str[i]; i++)
	{
		if (str[i] == c)
			return (i);
	}
	return (i);
}