#include "shell.h"
#include <sys/wait.h>

/**
 * command_exists - checks if command exists in path
 *
 * @command: (string) command to search for
 * Return: (int) 0 if command is found, -1 if not found
 */
int command_exists(char *string, char **av, char **env)
{
	char *env_name = getenv("PATH");
	char *dir = strtok(env_name, ":"), *argv[MAX_COMMAND];
	char *path;
	int i = 0, len;

	argv[0] = strtok(string, " ");
	while (argv[i])
		argv[++i] = strtok(NULL, " ");

	while (dir)
	{
		len = _strlen(env_name) + _strlen(dir);
		path = malloc(len);
		if (!path)
			return (-1);
		/* construct full path to command */
		snprintf(path, len, "%s/%s", dir, argv[0]);
		/* check if command exists && is executable */
		if (access(path, X_OK) == 0)
		{
			exec_command(path, argv, av, env);
			free(path);
			return (0);
		}
		/*if access() fails */
		free(path);
		dir = strtok(NULL, ":");
	}
	/* if command isn't found in the end */
	printf("%s: command not found\n", argv[0]);
	return (-1);
}

/**
 * exec_command - executes a command
*/
void exec_command(char *command_path, char *argv[], char **av, char **env)
{
	int status = 0;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
		free(command_path), exit(EXIT_FAILURE);
	if (child_pid == 0)
	{
		if (execve(command_path, argv, env) == -1)
			printf("%s: No such file or directory\n", av[0]);
	}
	else
		wait(&status);
}
