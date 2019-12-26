#include "uls.h"

void mx_print_permissions(char **permissions) {
    int j = 1;
    while(permissions[j]) {
        mx_printstr(",");
        mx_printstr(permissions[j]);
        j++;
    }
}


