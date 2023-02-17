#include "shell.h"

/**
 * main - receives a command for execution
 *
 * @ac: (int) argument count
 * @av: (array of string) argument vector
 * @env: (array of string) emvronment vector
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	if (ac == 1)
		prompt(av, env);

	return (0);
}
