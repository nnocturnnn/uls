#include "uls.h"

int mx_get_max_owner(t_file **all) {
	int i = 0;
	int max_size = 0;
    while(all[i] != NULL) {
        if(max_size < mx_strlen(all[i]->owner)) {
            max_size = mx_strlen(all[i]->owner);
        } 
        i++; 
    } 
    return max_size;   
}
