#include "uls.h"

void mx_cat_output(char **F, int *cur_flag, char *Directory) {
    t_file **all = (t_file **)malloc(sizeof(t_file) * 200000);
    int i = 0;

    all = mx_get_fileinfo(all, F, Directory, cur_flag);
    while (F[i] != NULL) {
        if (cur_flag[12]) {
            mx_printstr(all[i]->inode);
            mx_printstr(" ");
        }
        mx_printname_f(all[i], cur_flag);
        mx_printstr("\n");
        i++;
    }
}
