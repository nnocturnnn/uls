#include "uls.h"

static char get_type(struct stat file_stat);
static char get_mode(int mode, int user_type);
static char get_char(int mode, int is_exec, int is_id);

char *mx_get_permissions(struct stat file_stat) {
    char *permissions = mx_strnew(11);

    permissions[0] = get_type(file_stat); 
    permissions[1] = (file_stat.st_mode & S_IRUSR) ? 'r' : '-';
    permissions[2] = (file_stat.st_mode & S_IWUSR) ? 'w' : '-';
    permissions[3] = get_mode(file_stat.st_mode, 1);
    permissions[4] = (file_stat.st_mode & S_IRGRP) ? 'r' : '-';
    permissions[5] = (file_stat.st_mode & S_IWGRP) ? 'w' : '-';
    permissions[6] = get_mode(file_stat.st_mode, 2);
    permissions[7] = (file_stat.st_mode & S_IROTH) ? 'r' : '-';
    permissions[8] = (file_stat.st_mode & S_IWOTH) ? 'w' : '-';
    permissions[9] = get_mode(file_stat.st_mode, 4);
    return permissions;
}

static char get_type(struct stat file_stat) {
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

static char get_char(int mode, int is_exec, int is_id) {
    if (mode & is_exec) {
        if (mode & is_id)
            return 's';
        else
            return 'x';
    }
    else {
        if (mode & is_id)
            return 'S';
        else
            return '-';
    }
}

static char get_mode(int mode, int user_type) {
    if (user_type == 1)
        return get_char(mode, S_IXUSR, S_ISUID);
    else if (user_type == 2)
        return get_char(mode, S_IXGRP, S_ISGID);
    else {
        if (mode & S_IXOTH) {
            if (mode & S_ISTXT)
                return 't';
            else
                return 'x';
        }
        else {
            if (mode & S_ISTXT)
                return 'T';
            else 
                return '-';
        }
    }
}
