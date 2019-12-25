#include "uls.h"

static void color_dir(char *mode);
static void color_x(char *mode);
static void check_col_att(char *mode);

void mx_printname_f(t_file *file, int *cur_flag) {
    char *mode = file->permissions;
    if (cur_flag[2] && isatty(1)) { // -G
        check_col_att(mode);
    }
    mx_printstr(file->filename);
    if (cur_flag[19] && mode[0] == 'd')
        mx_printstr("/");
    if (cur_flag[2] && isatty(1)) {
        mx_printstr("\033[0m");
    }
}

static void color_dir(char *mode) {
    if (mode[5] == 'w' && mode[8] == 'w') {
        if (mode[9] == 't') {
            mx_printstr("\033[0;30;42m");
        }
        else {
            mx_printstr("\033[0;30;43m");
        }
    } 
    else {
        mx_printstr("\033[0;34m");
    }
}

static void color_x(char *mode) {
    if (mode[3] == 's') {
        mx_printstr("\033[0;30;41m");
    } else if (mode[6] == 's') {
        mx_printstr("\033[0;30;46m");
    } else {
       mx_printstr("\033[0;31m");
    }
}

static void check_col_att(char *mode) {
     if(mode[0] == 'd') {
       color_dir(mode);
    } else if (mode[0] == 'l') {
        mx_printstr("\033[0;35m");
    } else if (mode[9] == 'x') {
        color_x(mode);
    } else if (mode[0] == 's') {
        mx_printstr("\033[0;32m");
    } else if (mode[0] == 'p') {
        mx_printstr("\033[0;33m");
    } else if (mode[0] == 'b') {
        mx_printstr("\033[0;34;46m");
    } else if (mode[0] == 'c') {
        mx_printstr("\033[0;34;43m");
    }
}
