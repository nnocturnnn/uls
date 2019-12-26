#include "uls.h"

void mx_print_files(t_all all, char **F,  int *cur_flag) {
    if(all.n_files) {
        if(!all.priority[0] && !all.priority[10] 
           && !all.priority[13] && !all.priority[14]) {//long
            if(!isatty(1)) {// |cat -e
                mx_cat_output(F, cur_flag, ".");
            } else if (cur_flag[16] && all.priority[16]) {
                mx_1_output(F, cur_flag, ".");
            } else if (cur_flag[18] && all.priority[18]) {
                mx_m_output(F, cur_flag, "."); // m , 
            } else {// multicolumn output
                mx_multicolumn_output(F, all.n_files, cur_flag, ".");//standart
            }
        } else {//-l
            mx_long_output(F, cur_flag, ".");
        }
        if(all.n_dirs) {
            mx_printstr("\n");
        }
    }
}
