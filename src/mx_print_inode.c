#include "uls.h"

static int mx_get_max_inode(t_file **all);

void mx_print_inode(t_file *file, t_file **all, int *current_flags) {
    if(current_flags[12]) { // -i
        mx_space(mx_get_max_inode(all) - mx_strlen(file->inode));
        mx_printstr(file->inode);
        mx_printstr(" ");
    }
}


static int mx_get_max_inode(t_file **all) {
	int i = 0;
	int max_inode = 0;
    while(all[i] != NULL) {
        if(max_inode < mx_strlen(all[i]->inode)) {
            max_inode = mx_strlen(all[i]->inode);
        } 
        i++; 
    } 
    return max_inode;   
}
