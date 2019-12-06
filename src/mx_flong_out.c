#include "uls.h"

static void print_permission(t_file *file);
static void print_acl_attr(t_file *file);
static void print_links(t_file *file, t_file **all);
static void print_owner(t_file *file, t_file **all, int *cur_flag);

void mx_flong_out(t_file **all, int i, int *cur_flag) {
	mx_print_inode(all[i], all, cur_flag);
	print_permission(all[i]);// permissions
    print_acl_attr(all[i]);// acl attribute
    print_links(all[i], all);// links
    print_owner(all[i], all, cur_flag);// owner
}

static void print_permission(t_file *file) {
    mx_printstr(file->permissions);
}

static void print_acl_attr(t_file *file) {
    mx_printchar(file->acl_attr);// acl attribute
    mx_printstr(" ");
}

static void print_links(t_file *file, t_file **all) {
    mx_space(mx_get_max_links(all) - mx_strlen(file->links));
    mx_printstr(file->links); // links
    mx_printstr(" ");
}

static void print_owner(t_file *file, t_file **all, int *cur_flag) {
    if(!cur_flag[14]) {// -g
        mx_printstr(file->owner); // owner
        mx_space(mx_get_max_owner(all) - mx_strlen(file->owner));
        mx_printstr("  ");
    }
}
