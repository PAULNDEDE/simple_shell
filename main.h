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
void handle_signl(int signl);
int tokenizer(char *line, char **argv, int count);
int handle_builtin(char **args, char *input, char **argv, int count);
void prnt_env(char **envp);
void exit_program(char **tokens, char *input);
char *search_executable(char *token);
int execute_command(char **tokens, char **argv, char *input, int count);
char *process_input(char *input);
int convert_string_to_int(char *str);
void print_error(char **cmd, char **argv, int count);
void exit_error(char **tokens, char **argv, int count);
int print_number(int value);
int put_character(char ch);
int change_dir(char **args);
void err1(char **tokens, char **argv, int count);

#endif
