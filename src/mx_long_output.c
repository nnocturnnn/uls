#include "uls.h"

static void print_link(t_file *all);
static void print_inode(t_file *all, int *current_flags);
static void print_group(t_file *file, t_file **all, int *current_flags);
static void print_size(t_file *file, t_file **all, int *current_flags);
static void print_permission(t_file *file);
static void print_acl_attr(t_file *file);
static void print_links(t_file *file, t_file **all);
static void print_owner(t_file *file, t_file **all);
static void print_time(t_file *file, t_file **all, int *current_flags);

void mx_long_output(char **F, int *current_flags, char* Directory) {
    t_file **all = (t_file **)malloc(sizeof(t_file) * 200);
    all = mx_get_fileinfo(all, F, Directory, current_flags);
    int i = 0;

    while(all[i]!= NULL) {
        print_inode(all[i], current_flags); // inode
        print_permission(all[i]);// permissions
        print_acl_attr(all[i]);// acl attribute
        print_links(all[i], all);// links
        print_owner(all[i], all);// owner
        print_group(all[i], all, current_flags); // group
        print_size(all[i], all, current_flags); // size
        print_time(all[i], all, current_flags);// time
        mx_printname_f(all[i]->path, current_flags);// name
        print_link(all[i]); // link
        mx_printstr("\n");
        mx_xattr(current_flags, all[i], all);// -@ 
        mx_acl(current_flags, all[i]);// -e
        i++;
    }
    free(all);
}

static void print_link(t_file *file) {
    if(file->permissions[0] == 'l') { // links
        size_t linklen;
        linklen = readlink(file->path, NULL, 200);
        if(linklen != 0) {
            char *link  = malloc(10000);
            linklen = readlink(file->path, link, linklen);
            mx_printstr(" -> ");
            mx_printstr(link);
            free(link);
        }
    }
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

static void print_owner(t_file *file, t_file **all) {
    mx_printstr(file->owner); // owner
    mx_space(mx_get_max_owner(all) - mx_strlen(file->owner));
    mx_printstr("  ");
}

static void print_inode(t_file *file, int *current_flags) {
    if(current_flags[12]) { // -i
        mx_printstr(file->inode);
        mx_printstr(" ");
    }
}

static void print_group(t_file *file, t_file **all, int *current_flags) {
    if(!current_flags[10]) {// -o
        mx_printstr(file->group);
        mx_space(mx_get_max_group(all) - mx_strlen(file->group));
        mx_printstr("  ");
    }
}

static void print_size(t_file *file, t_file **all, int *current_flags) {
    if(!current_flags[6]) { // standart size
        mx_space(mx_get_max_size(all) - mx_strlen(file->size));
        mx_printstr(file->size);
    } else { //-h
        mx_space(mx_get_max_size_h(all) - mx_strlen(file->size_h) + 1);
        mx_printstr(file->size_h);
    }
    mx_printstr(" ");
}

static void print_time(t_file *file, t_file **all, int *current_flags) {
    if(!current_flags[5]) { // -T
        mx_space(mx_get_max_time(all) - mx_strlen(file->short_time));
        mx_printstr(file->short_time);
    } else {
        mx_printstr(file->full_time);
    }
    mx_printstr(" ");
}

