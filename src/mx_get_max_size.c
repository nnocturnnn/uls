#include "uls.h"

int mx_get_max_size(t_file **all) {
	int i = 0;
	int max_size = 0;
    while(all[i] != NULL) {
        if(max_size < mx_strlen(all[i]->size)) {
            max_size = mx_strlen(all[i]->size);
        } 
        i++; 
    } 
    return max_size;   
}
