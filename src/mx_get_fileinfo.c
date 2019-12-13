#include "uls.h"

static char *get_path(char *File, char *Directory);
static struct stat get_stat(char *path, int *cur_flag);
static time_t get_time(struct stat buff, int *cur_flag);
static void set_data(t_file *file, char *F, char* Directory,  int *cur_flag);

t_file **mx_get_fileinfo(t_file **all, char **F,char *Directory, int *cur_flag) {
    int i = 0; 
    while(F[i] != NULL) {
        all[i] = malloc(sizeof(t_file));// creation
        set_data(all[i], F[i], Directory, cur_flag);// getting file info
        i++;
    }
    all[i] = NULL;
    return all;
}

static void set_data(t_file *file, char *F, char* Directory,  int *cur_flag) {
    time_t current_time = time(0);
    char *path = get_path(F, Directory);//path
    struct stat buff = get_stat(path, cur_flag);// stat
    time_t time = get_time(buff, cur_flag);// full time

    file->path = path;// get path
    file->filename = F;// get name
    file->permissions = mx_get_permissions(buff);// get permisssion
    file->acl_attr = mx_get_acl(path, path);// get acl attribute
    file->links = mx_itoa(buff.st_nlink);// get links
    file->owner = mx_get_owner(buff, cur_flag);// get owner
    file->group = mx_get_group(buff, cur_flag);// get group
    file->size = mx_get_size(buff, cur_flag);// get size in standart format
    file->size_h = mx_get_sizeh(file->size);// get size in human readable format
    file->full_time = mx_get_full_time(time);// get time in long format
    file->short_time = mx_get_short_time(time, current_time);// get time in short format 
    file->inode = mx_sizetoa(buff.st_ino);// get inode(number of file)
}

static char *get_path(char *File, char *Directory) {
    char *path = malloc(sizeof(char *));
    if(!mx_strcmp(Directory, ".")) {
        path = File;
    } else {
        path = mx_strjoin(path,Directory);
        path = mx_strjoin(path,"/");
        path = mx_strjoin(path,File);
    }
    return path;
}

static struct stat get_stat(char *path, int *cur_flag) {
    struct stat buff;
    if (cur_flag[9]) {//-L
        stat(path, &buff);//without links
    } else {// standart
        lstat(path, &buff);//with links
    }
    return buff;
}

static time_t get_time(struct stat buff, int *cur_flag) {
    time_t time;
    if( cur_flag[11]) {// -u
        time = buff.st_atime;
    } else {
        time = buff.st_mtime;
    }
    return time;
}



