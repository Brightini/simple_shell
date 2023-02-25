#include "shell.h"

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated.
 * @old_size: The size in bytes of the allocated space for ptr.
 * @new_size: The size in bytes for the new memory block.
 *
 * Return: If new_size == old_size - ptr.
 *         If new_size == 0 and ptr is not NULL - NULL.
 *         Otherwise - a pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *mem;
	char *ptr_copy, *filler;
	unsigned int index;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		mem = malloc(new_size);
		if (mem == NULL)
			return (NULL);

		return (mem);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr_copy = ptr;
	mem = malloc(sizeof(*ptr_copy) * new_size);
	if (mem == NULL)
	{
		free(ptr);
		return (NULL);
	}

	filler = mem;

	for (index = 0; index < old_size && index < new_size; index++)
		filler[index] = *ptr_copy++;

	free(ptr);
	return (mem);
}

/**
 * assign_lineptr - Reassigns the lineptr variable for _getline.
 * @lineptr: A buffer to store an input string.
 * @n: The size of lineptr.
 * @buffer: The string to assign to lineptr.
 * @b: The size of buffer.
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * _getline - Reads input from a stream.
 * @lineptr: A buffer to store the input.
 * @n: The size of lineptr.
 * @stream: The stream to read from.
 *
 * Return: The number of bytes read.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t ret;
	char c = 'x', *buffer;
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}

		if (input >= 120)
			buffer = _realloc(buffer, input, input + 1);

		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';

	assign_lineptr(lineptr, n, buffer, input);

	ret = input;
	if (r != 0)
		input = 0;
	return (ret);
}
/*#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/*int lmstr(char *str);

int main()
{
char *ptr;
size_t n = 20, i;
ptr = malloc(sizeof(char) * n);
i = _getline(&ptr, &n, stdin);
printf("%s %ld", ptr, n);
return (0);
}*/

/*
/**
 * _getline - Print "$ " first with the string after it on next line
 * @lineptr: parameter of address holding buffer of string
 * @n: length of string
 * @stream: The stream to receive file;
 * Return: length of input string
 *//*
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t len = 120, *lenptr = &len, h;

	if (!(isatty(STDIN_FILENO)))
		printf("\n");
	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		perror("Error! wrong parameter or file pointer problem");
		return (-1);
	}
	if (*lineptr == NULL)
	{
		*lineptr = malloc(sizeof(char) * (*lenptr));
		if (*lineptr == NULL)
		{
			perror("Unable to allocate memory");
			return (-1);
		}
	}
	else
		*lineptr = realloc(*lineptr, *lenptr);
	while (1)
	{
		*lineptr = fgets(*lineptr, *lenptr, stream);
		h = lmstr(*lineptr);
		if (h > (*lenptr - 10))
		{
			*lenptr = (*lenptr) * 2;
			*lineptr = realloc(*lineptr, *lenptr);
			if (*lineptr == NULL)
				exit(1);
		}
		if (h < (*lenptr - 10))
			break;
	}
	if (h < (*lenptr - 10))
	{
		*lineptr = realloc(*lineptr, h + 1);
		if (*lineptr == NULL)
			exit (0);*/
		/*lineptr = fgets(*lineptr, (h + 1), stream);*/
/*		*n = lmstr(*lineptr);
		return (1);
	}
	return (-1);
}*/
		/*/**
 * _getline - Print "$ " first with the string after it on next l\ine
 * @lineptr: parameter of address holding buffer of string
 * @n: length of string
 * @stream: The stream to receive file;
 * Return: length of input string
 */
/*int lmstr(char *str)
{
	int i = 0;

	while (str[i] != '\n')
	{
		i++;
	}
	i++;
	return (i);
}
*/
