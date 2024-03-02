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
int tokenizer(char *line, char **argv, int count);
int builtin(char **tks, char *tk, char **argv, int count);
void shell_environ(void);
void shell_exit(char **token, char *utk);
char *search_executable(char *token);
int execute_command(char **tokens, char **argv, char *input, int count);
char *hash_handler(char *str);
int convert_string_to_int(char *str);
void print_error(char **cmd, char **argv, int count);
void exit_error(char **tokens, char **argv, int count);
int printer(int value);
void handle_signl(int signl);
int cd(char **tokens);
void shell_error(char **tkns, char **argv, int count);
int put_character(char ch);
int printer(int value);


#endif
