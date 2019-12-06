#include "uls.h"

static void print_link(t_file *all);
static void print_group(t_file *file, t_file **all, int *cur_flag);
static void print_size(t_file *file, t_file **all, int *cur_flag);
static void print_time(t_file *file, t_file **all, int *cur_flag);

void mx_slong_out(t_file **all, int i, int *cur_flag) {
	print_group(all[i], all, cur_flag); // group
    print_size(all[i], all, cur_flag); // size
    print_time(all[i], all, cur_flag);// time
    mx_printname_f(all[i]->path, cur_flag);// name
    print_link(all[i]); // link
    mx_printstr("\n");
    mx_xattr(cur_flag, all[i], all);// -@ 
    mx_acl(cur_flag, all[i]);// -e
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

static void print_group(t_file *file, t_file **all, int *cur_flag) {
    if(!cur_flag[10]) {// -o
        //mx_printstr("  ");
        mx_printstr(file->group);
        mx_space(mx_get_max_group(all) - mx_strlen(file->group));
        mx_printstr("  ");
    }
}

static void print_size(t_file *file, t_file **all, int *cur_flag) {
    if(cur_flag[10] && cur_flag[14]) {// -o & -g
        mx_printstr("  ");
    }
    if(!cur_flag[6]) { // standart size
        mx_space(mx_get_max_size(all) - mx_strlen(file->size));
        mx_printstr(file->size);
    } else { //-h
        mx_space(mx_get_max_size_h(all) - mx_strlen(file->size_h) + 1);
        mx_printstr(file->size_h);
    }
    mx_printstr(" ");
}

static void print_time(t_file *file, t_file **all, int *cur_flag) {
    if(!cur_flag[5]) { // -T
        mx_space(mx_get_max_time(all) - mx_strlen(file->short_time));
        mx_printstr(file->short_time);
    } else {
        mx_printstr(file->full_time);
    }
    mx_printstr(" ");
}
