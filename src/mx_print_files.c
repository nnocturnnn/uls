#include "uls.h"

void mx_print_files(int n_files, int n_dirs, char **F,  int *current_flags) {
    if(n_files) {
        if(!current_flags[0] && !current_flags[10]) {//without -l / -o
            if(!isatty(1)) {// |cat -e
                mx_cat_output(F, current_flags, ".");
            } else {// multicolumn output
                mx_multicolumn_output(F, n_files, current_flags, ".");
            }
        } else {//-l
            mx_long_output(F, current_flags, ".");
        }
        if(n_dirs) {
            mx_printstr("\n");
        }
    }
}
