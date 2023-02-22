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

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("Error: Fork issue");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(arr_str[0], arr_str, envp) == -1)
			printf("%s: No such file or directory\n", av[0]);
	}
	else
		wait(&status);
}
