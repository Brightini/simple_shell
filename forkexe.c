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

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: Fork issue");
		return;
	}
	if (child_pid == 0)
	{
		if (execvp(arstr[0], arstr) == -1)
			printf("./shell: No such file or directory\n");
	}
	else
	{
		wait(&status);
	}
}
