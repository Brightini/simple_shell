#include "shell.h"

void sig_handler(int sig);
int execute(char **args, char **front);

/**
 * sig_handler - Prints a new prompt upon a signal.
 * @sig: The signal.
 */
void sig_handler(int sig)
{
	char *new_prompt = "\n$ ";

	(void)sig;
	signal(SIGINT, sig_handler);
	write(STDIN_FILENO, new_prompt, 3);
}

/**
 * execute - Executes a command in a child process.
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If an error occurs - a corresponding error code.
 *         O/w - The exit value of the last executed command.
 */
int execute(char **args, char **front)
{
	pid_t child_pid;
	int status, flag = 0, ret = 0;
	char *command = args[0];

	if (command[0] != '/' && command[0] != '.')
	{
		flag = 1;
		command = get_location(command);
	}

	if (!command || (access(command, F_OK) == -1))
	{
		if (errno == EACCES)
			ret = (create_error(args, 126));
		else
			ret = (create_error(args, 127));
	}
	else
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			if (flag)
				free(command);
			perror("Error child:");
			return (1);
		}
		if (child_pid == 0)
		{
			execve(command, args, environ);
			if (errno == EACCES)
				ret = (create_error(args, 126));
			free_env();
			free_args(args, front);
			free_alias_list(aliases);
			_exit(ret);
		}
		else
		{
			wait(&status);
			ret = WEXITSTATUS(status);
		}
	}
	if (flag)
		free(command);
	return (ret);
}

/**
 * main - Runs a simple UNIX command interpreter.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: The return value of the last executed command.
 */
int main(int argc, char *argv[])
{
	int ret = 0, retn;
	int *exe_ret = &retn;
	char *prompt = "$ ", *new_line = "\n";

	name = argv[0];
	hist = 1;
	aliases = NULL;
	signal(SIGINT, sig_handler);

	*exe_ret = 0;
	environ = _copyenv();
	if (!environ)
		exit(-100);

	if (argc != 1)
	{
		ret = proc_file_commands(argv[1], exe_ret);
		free_env();
		free_alias_list(aliases);
		return (*exe_ret);
	}

	if (!isatty(STDIN_FILENO))
	{
		while (ret != END_OF_FILE && ret != EXIT)
			ret = handle_args(exe_ret);
		free_env();
		free_alias_list(aliases);
		return (*exe_ret);
	}

	while (1)
	{
		write(STDOUT_FILENO, prompt, 2);
		ret = handle_args(exe_ret);
		if (ret == END_OF_FILE || ret == EXIT)
		{
			if (ret == END_OF_FILE)
				write(STDOUT_FILENO, new_line, 1);
			free_env();
			free_alias_list(aliases);
			exit(*exe_ret);
		}
	}

	free_env();
	free_alias_list(aliases);
	return (*exe_ret);
}
/*#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
void freetins(char *nc, char *ptr, char **string);
void _EOF(char *buffer);
/**
 * main - Main for Built shell
 * @argc: number of arguments
 * @argv: Array of arguments
 * @envp: Array of environment variables
 * Return: Always 0.
 */
/*int main(int argc, char *argv[], char *envp[])
{
	char **string;
	size_t n = 20, imbt = 0, pt = 4;
	ssize_t num_char;
	char *ptr, *nc;

	if (argc > 1)
		argv[1] = NULL;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		ptr = malloc(sizeof(char) * n);
		if (ptr == NULL)
			exit(0);
		num_char = _getline(&ptr, &n, stdin);
		if (num_char == -1)
			break;
		if (*ptr != '\n')
		{
			string = chstrtok(ptr);
			if (_strcmp("exit", string[0]) == 0)
				break;
			imbt = checkinbuilt(string[0]);
			nc = filechk(string[0]);
			if (imbt == 0 &&  nc != NULL)
				string[0] = nc;
			pt = pathchk(string[0]);
			if (pt == 1)
				forkexe(string, envp);
			if (nc == NULL && pt == 0 && imbt == 0)
				printf("./shell: No such file or directory\n");
			fflush(stdin);
			freetins(nc, ptr, string);
		}
	}
	fflush(stdin);
	freetins(nc, ptr, string);
	exit(0);
}*/
/**
 * main - Main for Built shell
 * @argc: number of arguments
 * @argv: Array of arguments
 * @envp: Array of environment variables
 * Return: Always 0.
 */
/*void freetins(char *nc, char *ptr, char **string)
{
	if (nc)
		free(nc);
	free(ptr);
	free(string);
}*/
/**
 * _EOF - A function that chaecks if buffer is EOF
 * @buffer: The pointer to the input string.
 * Return: Nothing
 */
/*void _EOF(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}
*/
