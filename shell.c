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
	size_t n = 0, inbt, status;
	ssize_t num_char;
	char *line = NULL, *command_path, *err_mess, *error_message, **arr_str;

	if (argc > 1)
	{
		err_mess = _strcat("Usage: ", argv[0]);
		write(STDERR_FILENO, err_mess, _strlen(err_mess));
		write(STDERR_FILENO, "\n", 1), exit(EXIT_FAILURE);
	}
	while (1)
	{
		if (isatty(STDIN_FILENO)) /* for interactive mode only */
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
			else /* for commands with path */
				status = path_check(arr_str[0]);
			if (status == 0 || command_path)
			{
				exec_command(arr_str, argv, envp);
				if (isatty(STDIN_FILENO) == 0)
					exit(EXIT_SUCCESS);
			}
			if (status != 0 && !command_path && inbt == 0)
				write(STDERR_FILENO, error_message, _strlen(error_message));
		}
	}
	exit(EXIT_SUCCESS);
}
