#include "uls.h"

void mx_printname_f(char *F, int *current_flags) {
    struct stat buff;
    if(current_flags[9]){
        stat(F, &buff);
    } else {
        lstat(F, &buff);
    }
    char *mode = mx_get_permissions(buff);
    if(current_flags[2] && isatty(1)) { // -G
        if(mode[0] == 'd') {
            if(mode[5] == 'w' && mode[8] == 'w') {
                if(mode[9] == 't'){
                    mx_printstr("\033[0;30;42m");
                } else {
                    mx_printstr("\033[0;30;43m");
                }
            } else {
                mx_printstr("\033[0;34m");
            }
        } else if(mode[0] == 'l') {
            mx_printstr("\033[0;35m");
        } else if(mode[9] == 'x') {
            if(mode[3] == 's'){
                mx_printstr("\033[0;30;41m");
            } else if (mode[7] == 's'){
                mx_printstr("\033[0;30;46m");
            } else {
                mx_printstr("\033[0;31m");
            }
        } else if(mode[0] == 's') {
            mx_printstr("\033[0;32m");
        } else if(mode[0] == 'p') {
            mx_printstr("\033[0;33m");
        } else if(mode[0] == 'b') {
            mx_printstr("\033[0;34;46m");
        } else if(mode[0] == 'c') {
            mx_printstr("\033[0;34;43m");
        }
    }
    while(mx_strchr(F, '/') != NULL) {
        F = mx_strchr(F, '/');
        F++;
    }
    mx_printstr(F);
    if(current_flags[2] && isatty(1)) {
        mx_printstr("\033[0m");
    }
}

