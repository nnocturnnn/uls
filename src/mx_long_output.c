#include "uls.h"

void mx_long_output(char **F, int *cur_flag, char* Directory) {
    t_file **all = (t_file **)malloc(sizeof(t_file) * 200000);
    all = mx_get_fileinfo(all, F, Directory, cur_flag);
    int i = 0;

    while(all[i]!= NULL) {
        mx_flong_out(all, i, cur_flag);
        mx_slong_out(all, i, cur_flag);
        i++;
    }
    free(all);
}
