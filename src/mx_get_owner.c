#include "uls.h"

char *mx_get_owner(struct stat buff, int *current_flags) {
    char *owner = (char *)malloc(256);
    struct passwd* tmp = getpwuid(buff.st_uid);
    if(tmp == NULL || current_flags[13]) {// -n
    	owner = mx_itoa(buff.st_uid);
    } else {
        owner = mx_strcpy(owner,tmp->pw_name);
    }
    return owner;
}
