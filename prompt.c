#include "main.h"
#include <sys/wait.h>

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

/**
 * prompt - executes a command from terminal.
 *
 * @av: (array of string) argument vector
 * @env: (array of string) emvronment vector
 */
void prompt(char **av, char **env)
{
	pid_t child_pid;
	ssize_t num_char;
	size_t n = 0;
	int status;
	char *string = NULL, *argv[] = {NULL, NULL};

	while (1)
	{
		/* when input is expected from a user (interactive mode) */
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		num_char = getline(&string, &n, stdin);
		if (num_char == -1) /* handle EOF condition */
		{
			free(string);
			exit(EXIT_FAILURE);
		}

		/* removes newline character */
		string[_strcspn(string, '\n')] = 0;

		argv[0] = string;

		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
			wait(&status);
	}
	exit(EXIT_SUCCESS);
}
