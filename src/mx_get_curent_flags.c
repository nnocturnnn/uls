#include "uls.h"

int *mx_get_current_flags(char *flags) {           
    int *current_flags = malloc(sizeof(int) * mx_strlen(flags));
    for (int i = 0; i < mx_strlen(flags); i++) {
      current_flags[i] = 0;
    } 
    return current_flags;
}
