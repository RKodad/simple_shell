#ifndef SHELL_H
#define SHELL_H

#ifndef BUF_SIZE
#define BUF_SIZE 256
#endif

#ifndef DEBUG
#define DEBUG 0
#endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>

/* this function prints the simple shell user prompt */
int *print_prompt();
/* this function prints a character */
int print_char(char c);

void print_buffer(void *ptr, size_t n);
void print_horizontal_bar(unsigned long int i);
void strip_newline(char *s, ssize_t read);
char *get_fpath(char *cmd, char **env);
void _memset(void *s, int c, size_t n);
int _strncmp(char *s1, char *s2, int n);

void print_grid(char **grid);
void print_string(char *i);
void print_error(char *i);

char handle_builtins(char *cmd, char *line, char ***env);
void _free(char *line);
char handle_exec(char *cmd, char *line, char ***env);
int _strlen(const char *str);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strdup(char *str);
void canary(const char *s);
int _atoin(const char *s, int len);
int _isinteractive(void);
int valid_exitarg(char *arg, int len);
void print_help(void);

/* _cstrcmp - cut string compare */
int _cstrcmp(const char *s1, const char *s2);

/* _max - gives the max of two numbers */
int _max(int i, int j);

/* _min - gives the min of two numbers */
int _min(int i, int j);

/* _setenv - set an environment variable */
int _setenv(char ***env);

/* _setenv_func - helper to _setenv */
int _setenv_func(char ***env, char *x, char *y);

/* grow_env - grow env by one, copy all the present key-value pairs */
char **grow_env(char **env, int env_size);

/* new string with format "variable" + '=' + "value", like in PATH */
char *new_path_str(char *x, char *y);

/* replicate_env - duplicate the environment */
char **replicate_env(char **env);

void free_env(char **env);

void interrupt_handler(int a);

/* handle_comments - strips the comment section of line */
void handle_comments(char *line);

int _unsetenv(char ***env);

int _strcmp(const char *s1, const char *s2);

void shrink_env(char ***env, int d);

#endif
