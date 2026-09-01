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
*@input: the command entered
*@next: pointer to the next node
*@prev: pointer to previous node
*/
typedef struct historylist_s
{
	int id;
	char *input;
	struct historylist_s *next;
	struct historylist_s *prev;
} historylist_t;

extern char **environ;

int cd_func(int argc, char **argv);
void printbanner(void);
char *getline_reader();
int exit_func(int argc, char **argv);
void quick_sort(char **array, size_t size);
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
char *_getenv2(const char *name);
int handle_input(char *input, historylist_t *history_head, int *status);
int handle_condition(char *input, char spec, int *status);

#endif
