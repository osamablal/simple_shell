#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <sys/types.h>
#include <stdarg.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/stat.h>
#include <errno.h>

/*macros*/
#define BUFFER_SIZE 1024
#define PATH_SEPARATOR ":"
#define MAX_TOKENS 1024
#define PROMPT "$ "
#define PATH_MAX_LENGTH 4096

int hsh(char **);

/* Running Prompt : pro.c */
void pro(void);

/* Getting Input : ourget_input.c */
char *ourget_input(void);
void remove_previous_input(void);

/* Getting Line : _get_line.c*/
void *get_line(void);

/* BUILTIN functions : */
int our_check(char **args);
int our_execute(char *cmd, char **args);
void our_help(void);
void our_exit(char **args);
void our_cd(char **args);
int our_setenv(char **args);
int our_unsetenv(char **args);
int our_env(void);
int our_clear(char **args);

/* Handling Signals : oursig_handler.c */
void ourhandle_sigint(int sg);
void ourhandle_sigquit(int sg);
void ourhandle_sigstp(int sg);

/* Executing : execute.c */
int execute(char **args);

/* Tokens : ourtokenize.c */
char **tokenise(char *st, const char *del);
char **our_tokenise(char *input);

/* The Getenv : _ourget_env.c */
char *_ourgetenv(const char *nam);

/* Handling Path : ourget_path.c */
char *ourget_path(void);
char *ourfind_path(char *cmd);

/* Freeing up : remove.c */
void remove_error(char **argv, char *arg);
void remove_tokens(char **ptr);
void remove_path(void);

/* Putting Errors : our_puts.c */
void our_puts(char *st);
void our_puterror(char *erro);

/* String Functions : our_strings.c */
int our_strlen(const char *);
int our_strcmp(const char *st1, const char *st2);
int our_strncmp(const char *st1, const char *st2, size_t m);
char *our_strstr(char *stg, char *sstg);
char *our_strchr(char *k, char h);

/* String Functions : our_strings2.c */
char *our_strcpy(char *, char *);
char *our_strcat(char *, const char *);
char *our_strdup(const char *);
int our_putchar(char);
unsigned int our_strspn(char *j, char *p);

/* String Functions : our_strings3.c */
int our_atoi(const char *st);
char *our_memset(char *, char, unsigned int);
char *our_memcpy(char *z, char *v, unsigned int n);
void *our_realloc(void *, unsigned int, unsigned int);
void *our_calloc(unsigned int nmb, unsigned int siz);

#endif

