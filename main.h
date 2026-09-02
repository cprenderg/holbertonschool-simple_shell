#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
/*
*#include <readline/readline.h>
*#include <readline/history.h>
*/

/**
*struct historylist_s - node of a doubly linked list
*@id: number of the entry
*@user_input: the command entered
*@next: pointer to the next node
*@prev: pointer to previous node
*/
typedef struct historylist_s
{
	int id;
	char *user_input;
	struct historylist_s *next;
	struct historylist_s *prev;
} historylist_t;

typedef struct envlist_s 
{
	char *name;
	struct envlist_s *next;
} envlist_t;

extern char **environ;

int cd_func(int argc, char **argv);
void printbanner(void);
char *getline_reader();
int exit_func(int argc, char **argv);
char *readline_reader(void);
int get_argc(char *input);
char **get_argv(int argc, char *input);
void no_sigint(int);
historylist_t *history_func(char *input, historylist_t *head);
void print_history(historylist_t *head);
int path_execution(char **argv, int *status);
int function_search(char **argv, int *status);
void free_history(historylist_t *head);
char *_getenv(const char *name);
int handle_input(char *input, historylist_t *history_head, int *status, envlist_t **head);
int handle_condition(char *input, char spec, int *status);
char *_strtok(char *str, char *spec);
char *_strdup(char *str);
int _setenv(char **argv, envlist_t **head);
envlist_t *add_node_env(envlist_t **head, char *str);
void free_env(envlist_t *head);

int _unsetenv(const char *name);

#define RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[38;2;0;255;0m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_WHITE   "\033[37m"
#define FONT_BOLD    "\033[1m"

#endif
