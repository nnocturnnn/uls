#include "uls.h"

static char *get_time(time_t time, time_t current_time, 
                      char *full_time, char *short_time);

char *mx_get_short_time(time_t time, time_t current_time) {
    char *full_time = mx_strnew(3000);
    full_time = ctime(&time);
    char *short_time = mx_strnew(mx_strlen(full_time) - 13);
    
    return get_time(time, current_time, full_time, short_time);
}

static char *get_time(time_t time, time_t current_time, 
                      char *full_time, char *short_time) {
    if(current_time - time < 31556926 / 2  && ((current_time - time >= 0))) {
        short_time = mx_strncpy(short_time, full_time + 4, 
            mx_strlen(full_time) - 13);
    } 
    else {
        int m = 0;

        for (int j = 0; j < mx_strlen(full_time) - 1; j++) {
            if ((j > 3 && j < 11) || j > 19) {
                short_time[m] = full_time[j];
                m++;
            } 
            if (j == 11) {
                short_time[m] = ' ';
                m++;
            }
        }
    }
    return short_time; 
}
