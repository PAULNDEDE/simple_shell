#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
void control(int n);
int toker(char *line, char **argv, int count);
int builtin(char **tks, char *tk, char **argv, int count);
void env_fxn(void);
void exit_fxn(char **tks, char *tk/*, char **argv, int count*/);
char *find_path(char *first);
int exec_fxn(char **toks, char **argv, char *tk, int count);
char *hand_hash(char *str);
int a_toi(char *str);
void err(char **tokens, char **argv, int count);
void exit_err(char **tokens, char **argv, int count);
int printer(int value);
int put_char(char n);
int cd_fxn(char **tokens);
void err1(char **tokens, char **argv, int count);

#endif
