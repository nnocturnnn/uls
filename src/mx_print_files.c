#include "uls.h"

void mx_print_files(all_t all, char **F,  int *cur_flag) {
    if(all.n_files) {
        if(!cur_flag[0] && !cur_flag[10] && !cur_flag[14]) {//without -l / -o
            if(!isatty(1)) {// |cat -e
                mx_cat_output(F, cur_flag, ".");
            } else {// multicolumn output
                mx_multicolumn_output(F, all.n_files, cur_flag, ".");
            }
        } else {//-l
            mx_long_output(F, cur_flag, ".");
        }
        if(all.n_dirs) {
            mx_printstr("\n");
        }
    }
}
