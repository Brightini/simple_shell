#include "shell.h"

/**
 * exec_command - create child process to execute shell command
 *
 * @arr_str: Array of strings gotten from (tokenised) line command
 * @av: Array of strings from terminal
 * @envp: Environment variables from the parent
 * Return: void
 */
void exec_command(char **arr_str, char **av, char *envp[])
{
	pid_t child_pid;
	int status;
	char *err_message;

	err_message = _strcat(av[0], ": No such file or directory\n");

	child_pid = fork();
	if (child_pid < 0)
		free(arr_str), exit(EXIT_FAILURE);

	if (child_pid == 0)
	{
		if (execve(arr_str[0], arr_str, envp) == -1)
		{
			write(STDERR_FILENO, err_message, _strlen(err_message));
			exit(2);
		}
	}
	else
		wait(&status);
}
