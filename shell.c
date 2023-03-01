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
	size_t n = 0, inbt, status;
	ssize_t num_char;
	char *line = NULL, *command_path, *err_mess, *error_message;

	if (argc > 1)
	{
		err_mess = _strcat("Usage: ", argv[0]);
		write(STDERR_FILENO, err_mess, _strlen(err_mess));
		write(STDERR_FILENO, "\n", 1), exit(EXIT_FAILURE);
	}
	while (1)
	{
		/* for interactive mode only */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 10);
		/* fetch user's command from terminal */
		num_char = _getline(&line, &n, stdin);
		if (num_char == -1)
			free(line), exit(EXIT_FAILURE);
		if (*line != '\n')
		{
			arr_str = split_line(line);
			inbt = match_builtin(arr_str);
			error_message = _strcat(arr_str[0], ": command not found\n");
			/* for commands without path */
			command_path = create_path(arr_str[0]);
			if (command_path)
				arr_str[0] = command_path;
			/* for commands with path */
			else
				status = path_check(arr_str[0]);
			if (status == 0 || command_path)
				exec_command(arr_str, argv, envp);
			if (status != 0 && !command_path && inbt == 0)
				write(STDERR_FILENO, error_message, _strlen(error_message));
		}
	}
	exit(EXIT_SUCCESS);
}
