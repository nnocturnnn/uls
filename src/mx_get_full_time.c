#include "uls.h"

char *mx_get_full_time(char *full_time) {
    char *time = mx_strnew(mx_strlen(full_time) - 5);
    
    time = mx_strncpy(time, full_time + 4, mx_strlen(full_time) - 5);
    return time;
}
