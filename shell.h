#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/* main shell functions */
void prompt(void);
char *read_line(void);
char **split_line(char *line);
int execute(char **args, char *argv0, int count);
char *find_path(char *cmd);
void free_args(char **args);
void print_error(char *argv0, int count, char *cmd);
char *trim(char *str);
char *get_env_value(const char *name);
int handle_exit(char **args, char *line, char *path);
void handle_env(void);

#endif /* SHELL_H */
