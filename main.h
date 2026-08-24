#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct command_s{
    char *command;
    void (*function)(void);
} command_t;

void ls_func();
void printbanner(void);
char *line_reader(void);
void exit_func();

#endif
