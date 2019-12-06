#include "uls.h"

void mx_def_space(int *cur_flag, int j, int max, t_file **all, char **F) {
    if(!cur_flag[12]){ // standart(without inode)
        mx_space(max - mx_strlen(F[j]));
        if(cur_flag[2]) {// -G
            mx_space(1);
        } else { // standart output
            mx_printstr("\t");
        }
    } else { // -i
        mx_space(max - (mx_strlen(F[j]) + mx_strlen(all[j]->inode)));
    }
}
