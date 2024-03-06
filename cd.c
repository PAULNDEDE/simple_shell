#include "main.h"

int cd(char **tokens) {
    char cwd[PATH_MAX];
    char *home_dir = getenv("HOME");
    char *prev_dir = getenv("PWD");
    char *new_dir;
    int return_value = 0;
    
    char *last_slash;

    
    if (tokens[1] == NULL) {
        new_dir = home_dir;
    }
   
    else if (strcmp(tokens[1], "-") == 0) {
        if (prev_dir == NULL) {
            fprintf(stderr, "cd: OLDPWD not set\n");
            return -1;
        }
        new_dir = prev_dir;
    }
   
    else if (strcmp(tokens[1], "..") == 0) {
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            perror("getcwd");
            return -1;
        }
        last_slash = strrchr(cwd, '/');
        if (last_slash == NULL) {
            fprintf(stderr, "cd: cannot go to parent directory\n");
            return -1;
        }
        *last_slash = '\0';
        new_dir = cwd;
    }
   
    else {
        new_dir = tokens[1];
    }

  
    return_value = chdir(new_dir);
    if (return_value == -1) {
        perror("cd");
        return -1;
    }

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        return -1;
    }
    if (setenv("PWD", cwd, 1) == -1) {
        perror("setenv");
        return -1;
    }
    if (setenv("OLDPWD", prev_dir != NULL ? prev_dir : "", 1) == -1) {
        perror("setenv");
        return -1;
    }

    return 0;
}
