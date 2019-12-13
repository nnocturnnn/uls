#include "uls.h"

char *mx_get_full_time(time_t time) {
	char *full_time = mx_strnew(3000);
    full_time = ctime(&time);
    char *long_time = mx_strnew(mx_strlen(full_time) - 5);
    
    long_time = mx_strncpy(long_time, full_time + 4, mx_strlen(full_time) - 5);
    return long_time;
}
