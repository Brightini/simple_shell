#ifndef SHELL_H
#define SHELL_H

/* Macros */
#define MAX_COMMAND 20 /* max number of commands to be run */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void prompt(char **, char **);
void exec_command(char *, char *[], char **, char **);
int command_exists(char *, char **, char **);

/* in string_func.c file */
int _strlen(char *);
size_t _strcspn(const char *, char);

#endif
