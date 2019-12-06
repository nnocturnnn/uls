#include "uls.h"

int *mx_get_current_flags(char *flags) {
    int *cur_flag = malloc(sizeof(int) * mx_strlen(flags));
    for (int i = 0; i < mx_strlen(flags); i++) {
      cur_flag[i] = 0;
    } 
    return cur_flag;
}
