#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

/* Function prototype for didplsying a prompt*/
void display_prompt(void);
void execute_cmd(char *cmd);

/*prototype for execute command file*/
void execute_cmd(char *cmd_line);

#endif
