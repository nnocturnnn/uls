#include "uls.h"

static char *get_path(char *File, char *Directory);
static void set_data(t_file *file, char *F, char *Directory, int *cur_flag);
static struct stat get_stat(char *path, int *cur_flag);
static time_t get_time(struct stat buff, int *cur_flag);

t_file **mx_get_fileinfo(t_file **all, char **F, 
                         char *Directory, int *cur_flag) {
    int i = 0;

    while(F[i] != NULL) {
        all[i] = malloc(sizeof(t_file));
        set_data(all[i], F[i], Directory, cur_flag);
        i++;
    }
    all[i] = NULL;
    return all;
}

static void set_data(t_file *file, char *F, char *Directory, int *cur_flag) {
    time_t current_time = time(0);
    char *path = get_path(F, Directory);
    struct stat buff = get_stat(path, cur_flag);
    time_t time = get_time(buff, cur_flag); 

    file->path = path;
    file->filename = F;
    file->permissions = mx_get_permissions(buff);
    file->acl_attr = mx_get_acl(path, path);
    file->links = mx_itoa(buff.st_nlink);
    file->owner = mx_get_owner(buff, cur_flag);
    file->group = mx_get_group(buff, cur_flag);
    file->size = mx_get_size(buff, cur_flag);
    file->size_h = mx_get_size_h(file->size);
    file->full_time = mx_get_full_time(time);
    file->short_time = mx_get_short_time(time, current_time);
    file->inode = mx_sizetoa(buff.st_ino);
}

static char *get_path(char *File, char *Directory) {
    char *path = malloc(sizeof(char *));

    if(!mx_strcmp(Directory, "."))
        path = File;
    else {
        path = mx_strjoin(path,Directory);
        path = mx_strjoin(path,"/");
        path = mx_strjoin(path,File);
    }
    return path;
}

static struct stat get_stat(char *path, int *cur_flag) {
    struct stat buff;

    if (cur_flag[9]) //-L
        stat(path, &buff);//without links
    else // standart
        lstat(path, &buff);//with links
    return buff;
}

static time_t get_time(struct stat buff, int *cur_flag) {
    time_t time;

    if(cur_flag[11]) // -u
        time = buff.st_atime;
    else
        time = buff.st_mtime;
    return time;
}
