#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

char *filechk(char *str);
char *_strcat(char *des, char *src);
char *_strcpy(char *dest, const char *src);
int _strcmp(char *fi, char *sd);
void prompt(char **, char **);
int checkinbuilt(char *str);
void forkexe(char **arstr, char *envp[]);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int pathchk(char *str);
char **chstrtok(char *str);
#endif
