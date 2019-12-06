#include "uls.h"

char *mx_get_group(struct stat buff, int *cur_flag) {
    char *group;
    struct group *tmp_g = getgrgid(buff.st_gid);
    if(tmp_g == NULL || cur_flag[13]) { //-n
        group = mx_itoa(buff.st_gid);
    } else {
        group = tmp_g->gr_name;
    }
    return group;
}
