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
#include <readline/readline.h>
#include <readline/history.h>
*/
/** typedef struct command_s{
    char *command;
 int (*function)(int argc, char **argv);
} command_t; */

typedef struct historylist_s{
    int id;
    char *user_input;
    struct historylist_s *next;
    struct historylist_s *prev;
} historylist_t;

int cd_func(int argc, char **argv);
void printbanner(void);
char *getline_reader();
int exit_func(int argc, char **argv);
void quick_sort(char **array, size_t size);
char *readline_reader(void);
int get_argc(char *user_input);
char **get_argv(int argc, char *user_input);
void no_sigint(int);
historylist_t *history_func(char *user_input, historylist_t *head);
void print_history(historylist_t *head);
int path_execution(char **argv, int *last_status);
int function_search(char **argv, int *last_status);
void free_history(historylist_t *head);
char *_getenv(const char *name);
char *_getenv2(const char *name);
int handle_user_input(char *user_input, historylist_t *history_head, int *last_status);
int handle_condition(char *user_input, char spec, int *last_status);

#endif
