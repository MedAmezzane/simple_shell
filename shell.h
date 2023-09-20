#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define DELIM " \n\t"

extern char **environ;

char *read_line(void);
char **tokenize_input(char *line);
int execute_command(char **parsed_command, char **argv, int index);

char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

void free2DArray(char **array);
void printNotFoundError(char *programName, char *command, int index);
char *_itoa(int n);
void reverse_string(char *str, int len);

char *getEnvironmentVariable(char *variableName);
char *getPath(char *command);


#endif
