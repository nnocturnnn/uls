#include "uls.h"

void mx_print_user(char ***data, char **permissions, int number) {
    mx_printstr(" ");
    mx_printstr(mx_itoa(number));
    mx_printstr(": ");
    mx_printstr(data[number][0]);
    mx_printstr(":");
    mx_printstr(data[number][2]);
    mx_printstr(" ");
    mx_printstr(permissions[0]);
    mx_printstr(" ");
}


