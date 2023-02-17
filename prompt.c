#include "shell.h"

/**
 * prompt - executes a command from terminal.
 *
 * @av: (array of string) argument vector
 * @env: (array of string) emvronment vector
 */
void prompt(char **av, char **env)
{
	ssize_t num_char;
	size_t n = 0;
	int check;
	char *string = NULL;

	while (1)
	{
		/* when input is expected from a user (interactive mode) */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 10);

		num_char = getline(&string, &n, stdin);
		if (num_char == -1) /* handle EOF condition */
			free(string), exit(EXIT_FAILURE);

		/* removes newline character */
		string[_strcspn(string, '\n')] = 0;

		check = command_exists(string, av, env);
		if (check == -1)
			continue;
	}
	free(string), exit(EXIT_SUCCESS);
}
