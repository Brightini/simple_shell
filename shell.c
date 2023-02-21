#include "shell.h"

/**
 * main - Entry point for shell program
 * @argc: number of arguments
 * @argv: Array of arguments
 * @envp: Array of environment variables
 * Return: Always 0.
 */
int main(int argc, char *argv[], char *envp[])
{
	char **arr_str;
	size_t n = 0, status;
	ssize_t num_char;
	char *line = NULL, *command_path;

	if (argc > 1)
		argv[1] = NULL;
	while (1)
	{
		/* for interactive mode only */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 10);
		/* fetch user's command from terminal */
		num_char = getline(&line, &n, stdin);
		if (num_char == -1)
			free(line), exit(EXIT_FAILURE);

		if (*line != '\n')
		{
			arr_str = split_line(line);
			if (_strcmp("exit", arr_str[0]) == 0)
				free(line), exit(EXIT_FAILURE);

			/* for commands without path */
			command_path = create_path(arr_str[0]);
			if (command_path)
				arr_str[0] = command_path;
			/* for commands with path */
			else
				status = path_check(arr_str[0]);

			if (status == 1 || command_path)
				exec_command(arr_str, argv, envp);
			if (status != 1 && !command_path)
				printf("%s: command not found\n", arr_str[0]);
		}
	}
	free(arr_str);
	free(line);
	exit(0);
}
