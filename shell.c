#include "shell.h"
void prompt(char **av, char **env);

/**
 * main - Entry point for shell program
 * @ac: number of arguments
 * @av: Array of arguments
 * @env: Array of environment variables
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    if (ac == 1)
        prompt(av, env);
    return (0);
}
