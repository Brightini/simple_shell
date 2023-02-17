#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int filechk(char *str);
int _strcmp(char *fi, char *sd);
void prompt(char **, char **);
int checkinbuilt(char *str);
void forkexe(char **arstr);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char **chstrtok(char *str);
#endif
