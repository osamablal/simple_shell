#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <limits.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

#define USE_GETLINE 0
#define USE_STRTOK 0

extern char **environ;

/**
 * struct liststr - The Linked List.
 * @num: Number.
 * @stg: String.
 * @next: Next Node.
 */
typedef struct liststr
{
	int num;
	char *stg;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - It have psoudo args to go through a function.
 *@arg: String having arguements.
 *@argv: Array of strings.
 *@argc: Argument Counting.
 *@path: String path for current comand.
 *@line_count: Error Counting.
 *@fname: File name.
 *@err_num: Error of exit.
 *@linecount_flag: If in counting that line in input.
 *@alias: Alias Node.
 *@histcount: History number counts.
 *@env: Linked list the copy of the environ.
 *@environ: Modified copy of env.
 *@history: History Node.
 *@env_changed: If environ changes.
 *@status: Return status of  prevois command.
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@cmd_buf: place Pointer to cmd_buf, in chain.
 *@readfd: FD from that we read line input from.
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_nme;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - Have BUILT-IN string and it's function.
 *@type: Command flag.
 *@func: Function.
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


int hsh(info_t *, char **);
int ourfind_builtin(info_t *);
void ourfind_cmd(info_t *);
void our_forkcmd(info_t *);
int ouris_cmd(info_t *, char *);
char *ourdup_chars(char *, int, int);
char *ourfind_path(info_t *, char *, char *);
int our_loop(char **);
void our_eputs(char *);
int our_eputchar(char);
int our_putfd(char c, int fd);
int our_putsfd(char *str, int fd);
int our_strlen(char *);
int our_strcmp(char *, char *);
char *our_starts(const char *, const char *);
char *our_strcat(char *, char *);
char *our_strcpy(char *, char *);
char *our_strdup(const char *);
void _puts(char *);
int _putchar(char);
char *our_strncpy(char *, char *, int);
char *our_strncat(char *, char *, int);
char *our_strchr(char *, char);
char **ourstrtow(char *, char *);
char **ourstrtow2(char *, char);
char *our_memset(char *, char, unsigned int);
void our_free(char **);
void *our_realloc(void *, unsigned int, unsigned int);
int our_pfree(void **);
int intrctv(info_t *);
int isdlm(char, char *);
int islph(int);
int _atoi(char *);
int our_err(char *);
void our_printerr(info_t *, char *);
int our_printd(int, int);
char *ourconvert_num(long int, int, int);
void ourfree_comments(char *);
int our_exit(info_t *);
int our_cd(info_t *);
int our_help(info_t *);
int our_history(info_t *);
int our_alias(info_t *);
ssize_t our_getinput(info_t *);
int _getline(info_t *, char **, size_t *);
void oursign_Handler(int);
void our_clearinf(info_t *);
void our_setinf(info_t *, char **);
void our_freeinf(info_t *, int);
char *our_getenv(info_t *, const char *);
int our_env(info_t *);
int our_setenv(info_t *);
int our_unsetenv(info_t *);
int our_envlist(info_t *);
char **get_environ(info_t *);
int our_unsetenv(info_t *, char *);
int our_setenv(info_t *, char *, char *);
char *ourget_hisfile(info_t *info);
int ourwrithis(info_t *info);
int ourredhis(info_t *info);
int our_bldhislst(info_t *info, char *buf, int linecount);
int our_numhis(info_t *info);
list_t *ouradd_node(list_t **, const char *, int);
list_t *ouradd_nodeend(list_t **, const char *, int);
size_t ourprint_list(const list_t *);
int ourdelete_node(list_t **, unsigned int);
void ourfree_list(list_t **);
size_t ourlist_len(const list_t *);
char **ourlist_string(list_t *);
list_t *ournode_start(list_t *, char *, char);
ssize_t ourget_nodindx(list_t *, list_t *);
int ouris_chain(info_t *, char *, size_t *);
void ourcheck_chain(info_t *, char *, size_t *, size_t, size_t);
int ourreplace_alias(info_t *);
int ourreplace_vars(info_t *);
int ourreplace_string(char **, char *);

#endif

