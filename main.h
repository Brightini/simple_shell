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

char *create_path(char *);
void prompt(char **, char **);
void exec_command(char **, char **, char **);
ssize_t _getline(char **, size_t *, FILE *);
int path_check(char *);
char **split_line(char *);

/* In string_func.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *_strcat(char *, char *);

#endif
