#include "uls.h"

static char *get_path(char *File, char *Directory);
static struct stat get_stat(char *path, int *current_flags);
static char *get_permissions(struct stat buff);
static char get_acl_attr(char *path);
static char *get_long_time(time_t time);
static char *get_short_time(time_t current_time, time_t time);
static time_t get_time(struct stat buff, int *current_flags);

t_file **mx_get_fileinfo(t_file **all, char **F, char *Directory, int *current_flags) {
	time_t current_time = time(0);
    int i = 0; 
    while(F[i] != NULL) {
        all[i] = malloc(sizeof(t_file));// creation
        char *path = get_path(F[i], Directory);//path
        struct stat buff = get_stat(path, current_flags);// stat
        time_t time = get_time(buff, current_flags);// full time

        all[i]->path = path;// get path
        all[i]->filename = F[i];// get name
        all[i]->permissions = get_permissions(buff);// get permisssion
        all[i]->acl_attr = get_acl_attr(path);// get acl attribute
        all[i]->links = mx_itoa(buff.st_nlink);// get links
        all[i]->owner = mx_get_owner(buff, current_flags);// get owner
        all[i]->group = mx_get_group(buff, current_flags);// get group
        all[i]->size = mx_sizetoa(buff.st_size);// get size in standart format
        all[i]->size_h = mx_get_sizeh(all[i]->size);// get size in human readable format
        all[i]->full_time = get_long_time(time);// get time in long format
        all[i]->short_time = get_short_time(current_time, time);// get time in short format 
        all[i]->inode = (mx_sizetoa(buff.st_ino));// get inode(number of file)
        i++;
    }
    all[i] = NULL;
    return all;
}

static char *get_path(char *File, char *Directory) {
    char *path = malloc(sizeof(char *));
    path = mx_strjoin(path,Directory);
    path = mx_strjoin(path,"/");
    path = mx_strjoin(path,File);
    return path;
}

static struct stat get_stat(char *path, int *current_flags) {
    struct stat buff;
    if(current_flags[9]) {//-L
        stat(path, &buff);//without links
    } else {// standart
        lstat(path, &buff);//with links
    }
    return buff;
}

static char *get_permissions(struct stat buff) {
    char *mode = mx_get_permissions(buff);
    return mode;
}

static char get_acl_attr(char *path) {
    char acl =  mx_get_acl(path);
    return acl;
}

static time_t get_time(struct stat buff, int *current_flags) {
    time_t time;
    if(current_flags[11]) {// -u
        time = buff.st_atime;
    } else {
        time = buff.st_mtime;
    }
    return time;
}

static char *get_long_time(time_t time) {
    char *full_time = mx_strnew(3000);
    full_time = ctime(&time);
    char *long_time = mx_get_full_time(full_time);
    return long_time;
}


static char *get_short_time(time_t current_time, time_t time) {
    char *full_time = mx_strnew(3000);
    full_time = ctime(&time);
    char *short_time = mx_get_short_time(time, full_time, current_time);
    return short_time;
}


