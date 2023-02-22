#ifndef MAIN_H
#define MAIN_H

#define MAX_COMMANDS 20

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * struct builtin_s - struct for built-in commands
 *
 * @command: built-in command to be executed
 * @fptr: function pointer to execute built-in command
*/
typedef struct builtin_s
{
	char *command;
	size_t (*fptr)(char **);
} builtin_t;

char *create_path(char *);
void exec_command(char **, char **, char **);
ssize_t _getline(char **, size_t *, FILE *);
int path_check(char *);
char **split_line(char *);

/* In string_func.c */
int _strlen(char *);
int _atoi(char *);
int _strcmp(char *, char *);
char *_strcat(char *, char *);

/* In builtin_func.c file */
size_t my_exit(char **);
size_t _setenv(char **);

/* In match_builtin.c */
size_t match_builtin(char **);

#endif
