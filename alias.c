#include "main.h"

struct Alias {
    char name[MAX_ALIAS_LEN];
    char value[MAX_ALIAS_LEN];
};

struct Alias aliases[MAX_ALIASES];
int num_aliases = 0;

void print_all_aliases() {
    int i;
    for (i = 0; i < num_aliases; i++) {
        printf("%s='%s'\n", aliases[i].name, aliases[i].value);
    }
}

void print_alias(const char *name) {
    int i;
    for (i = 0; i < num_aliases; i++) {
        if (strcmp(aliases[i].name, name) == 0) {
            printf("%s='%s'\n", aliases[i].name, aliases[i].value);
            return;
        }
    }
    printf("Alias '%s' not found\n", name);
}

void set_alias(const char *name, const char *value) {
    int i;
    for (i = 0; i < num_aliases; i++) {
        if (strcmp(aliases[i].name, name) == 0) {
            strcpy(aliases[i].value, value);
            return;
        }
    }
    if (num_aliases < MAX_ALIASES) {
        strcpy(aliases[num_aliases].name, name);
        strcpy(aliases[num_aliases].value, value);
        num_aliases++;
    } else {
        printf("Maximum number of aliases reached\n");
    }
}

