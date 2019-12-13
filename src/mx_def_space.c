#include "uls.h"

void mx_def_space(int *cur_flag, int j, int max, t_file **all) {
    if (cur_flag[12]) {// -i
        mx_space(max - mx_strlen(all[j]->filename) 
        - mx_strlen(all[j]->inode) - 1);
    } 
    else {// standart output
        mx_space(max - mx_strlen(all[j]->filename));
    }
    if (cur_flag[2]) {// -G
        mx_space(1);
    } 
    else { // standart output
         mx_printstr("\t");
    }
}
