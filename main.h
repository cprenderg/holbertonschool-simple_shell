#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct command_s{
    char *command;
    int (*function)(int argc, char **argv);
} command_t;


int cd_func(int argc, char **argv);
void printbanner(void);
char *getline_reader(void);
int exit_func(int argc, char **argv);
void quick_sort(char **array, size_t size);
int function_search(char **argv);
char *readline_reader(void);


#endif
