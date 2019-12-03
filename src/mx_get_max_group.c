#include "uls.h"

int mx_get_max_group(t_file **all) {
	int i = 0;
	int max_size = 0;
    while(all[i] != NULL) {
        if(max_size < mx_strlen(all[i]->group)) {
            max_size = mx_strlen(all[i]->group);
        } 
        i++; 
    } 
    return max_size;   
}
