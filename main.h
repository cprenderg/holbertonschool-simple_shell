#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>

typedef struct command_s{
    char *command;
    void (*function)(void);
} command_t;

void exit_func();
void ls_func();

#endif
