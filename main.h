#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct command_s{
    char *command;
    int (*function)(int argc, char **argv);
} command_t;



void printbanner(void);
char *line_reader(void);
int exit_func(int argc, char **argv);
int ls_func(int argc, char **argv);
void quick_sort(char **array, size_t size);
int function_search(int argc, char **argv);


#endif
