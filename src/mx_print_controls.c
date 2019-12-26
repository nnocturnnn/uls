#include "uls.h"

void mx_print_controls(char **new_controls) {
    int j = 0;
    while(new_controls[j] != NULL) {
        mx_printstr(new_controls[j]);
        if(new_controls[j + 1] != NULL) {
            mx_printchar(',');
        }
        j++;
    }
}


