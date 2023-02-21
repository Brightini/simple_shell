#include "shell.h"

/**
 * _strcat - concatenates string
 *
 * @des: dest parameter
 * @src: source parameter
 * Return: The concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int a, b, c, i = 0, j = 0;
	char *new;

	a = _strlen(dest);
	b = _strlen(src);
	c = a + b + 1; /* +1 to include terminating null byte*/
	new = malloc(sizeof(char) * c);
	if (new == NULL)
		return (NULL);
	/* copies dest to new */
	for (i = 0; i < a; i++)
		new[i] = dest[i];
	/* overwrites terminating null byte in @new and begins appending @src */
	while (j < b)
		new[i] = src[j], i++, j++;

	new[i] = '\0';
	return (new);
}

/**
 * _strcmp - compare two string
 *
 * @first: First string
 * @sec: Second string
 * Return: 0 if @first and @sec are the same, otherwise 1
 */
int _strcmp(char *first, char *sec)
{
	int i = 0, len;

	len = _strlen(first);
	while (sec[i] != '\0')
	{
		if (sec[i] != first[i])
			return (1);
		i++;
	}
	if (len != i)
		return (1);
	return (0);
}

/**
 * _strlen - computes the length of a string
 * excluding terminating null byte
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
