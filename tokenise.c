#include "main.h"

/**
 * split_line - tokenizes a string
 *
 * @str: string parameter (command from the terminal)
 * Return: Array of strings
 */
char **split_line(char *str)
{
	char **arr_str, *token;
	int i = 0, j = 0;

	arr_str = malloc(MAX_COMMANDS * sizeof(char *));
	if (arr_str == NULL)
		perror("Can't allocate space\n"), exit(EXIT_FAILURE);

	/* to eliminate newline character */
	while (str[j])
	{
		if (str[j] == '\n')
			str[j] = '\0';
		j++;
	}
	/* then tokenize */
	token = strtok(str, " ");
	while (token != NULL)
	{
		arr_str[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	arr_str[i] = NULL; /* to indicate end of array */
	return (arr_str);
}
