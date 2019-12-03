#include "uls.h"

static char mx_get_type(struct stat file_stat);

char *mx_get_permissions(struct stat file_stat) {
    char *permissions = mx_strnew(11);
    permissions[0] = mx_get_type(file_stat); 
    permissions[1] = (file_stat.st_mode & S_IRUSR) ? 'r' : '-';
    permissions[2] = (file_stat.st_mode & S_IWUSR) ? 'w' : '-';
    permissions[3] = (file_stat.st_mode & S_IXUSR) ? 'x' : '-';
    permissions[4] = (file_stat.st_mode & S_IRGRP) ? 'r' : '-';
    permissions[5] = (file_stat.st_mode & S_IWGRP) ? 'w' : '-';
    permissions[6] = (file_stat.st_mode & S_IXGRP) ? 'x' : '-';
    permissions[7] = (file_stat.st_mode & S_IROTH) ? 'r' : '-';
    permissions[8] = (file_stat.st_mode & S_IWOTH) ? 'w' : '-';
    permissions[9] = (file_stat.st_mode & S_IXOTH) ? 'x' : '-';
    if(file_stat.st_mode & S_ISTXT) {
        permissions[9] = 't';
    }
    return permissions;
}

static char mx_get_type(struct stat file_stat) {
    char result = '-';
    if ((file_stat.st_mode & S_IFMT) == S_IFCHR)
        return 'c';
    if ((file_stat.st_mode & S_IFMT) == S_IFBLK)
        return 'b';
    if ((file_stat.st_mode & S_IFMT) == S_IFIFO)
        return 'p';
    if ((file_stat.st_mode & S_IFMT) == S_IFSOCK)
        return 's';
    if ((file_stat.st_mode & S_IFMT) == S_IFLNK)
        return 'l';
    if ((file_stat.st_mode & S_IFMT) == S_IFDIR)
        return 'd';
    return result;
}
