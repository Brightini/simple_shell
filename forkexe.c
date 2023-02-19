#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * forkexe - System execution with fork
 * @arstr: Array of strings gotten from line command
 * Return: int.
 */
void forkexe(char **arstr)
{
	pid_t child_pid;
	int status;
	char *envp[] = {
		"USER=julien",
		"LANGUAGE=en_US",
		"SESSION=ubuntu",
		"COMPIZ_CONFIG_PROFILE=ubuntu",
		"SHLVL=1",
		"HOME=/home/julien",
		"C_IS=Fun_:)",
		"DESKTOP_SESSION=ubuntu",
		"LOGNAME=julien",
		"TERM=xterm-256color",
		"PATH=/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:"
		"/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bi"
		"n:/usr/games:/usr/local/games:/snap/bin",
		"DISPLAY=:0",
		NULL
	};

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("Error: Fork issue");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(arstr[0], arstr, envp) == -1)
			perror("./shell: No such file or directory\n");
	}
	else
	{
		wait(&status);
	}
}
