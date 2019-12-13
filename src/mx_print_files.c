#include "uls.h"

void mx_print_files(all_t all, char **F,  int *cur_flag) {
    if(all.n_files) {
        if(!all.priority[0] && !all.priority[10] && !all.priority[13] && !all.priority[14]) {
            if(!isatty(1)) {// |cat -e
                mx_cat_output(F, cur_flag, ".");
            } else if (cur_flag[16] && all.priority[16]) {
                mx_1_output(F, cur_flag, ".");
            } else if (cur_flag[18] && all.priority[18]) {
                mx_m_output(F, cur_flag, ".");
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
