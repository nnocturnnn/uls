#include "uls.h"

void mx_cat_output(char **F, int *current_flags, char *Directory) {
	t_file **all = (t_file **)malloc(sizeof(t_file) * 200);
    all = mx_get_fileinfo(all, F, Directory, current_flags);
    int i = 0;
    while(F[i] != NULL) {
    	if(current_flags[12]) { // -i
            mx_printstr(all[i]->inode);
            mx_printstr(" ");
        }
        mx_printname_f(F[i], current_flags);
        mx_printstr("\n");
        i++;
    }
}
