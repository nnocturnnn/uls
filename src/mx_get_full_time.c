#include "uls.h"

char *mx_get_full_time(/*struct stat buff,*/ char *full_time/*, time_t current_time*/) {
    char *time = mx_strnew(mx_strlen(full_time) - 5);
    
    time = mx_strncpy(time, full_time + 4, mx_strlen(full_time) - 5);
    return time;
}
