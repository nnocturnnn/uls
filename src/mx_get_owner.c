#include "uls.h"

char *mx_get_owner(struct stat buff, int *cur_flag) {
    char *owner = (char *)malloc(256);
    struct passwd* tmp = getpwuid(buff.st_uid);

    if (tmp == NULL || cur_flag[13]) 
        owner = mx_itoa(buff.st_uid);
    else
        owner = mx_strcpy(owner, tmp->pw_name);
    return owner;
}
