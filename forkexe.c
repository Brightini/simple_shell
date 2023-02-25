/*#include "main.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * forkexe - System execution with fork
 * @arstr: Array of strings gotten from line command
 * @envp: Environment variables from the parent
 * Return: void
 */
/*void forkexe(char **arstr, char *envp[])
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
		if (execve(arstr[0], arstr, envp) == -1)
			perror("./shell: No such file or directory\n");
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
*/
