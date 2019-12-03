#include "uls.h"

int mx_get_max_size_h(t_file **all) {
	int i = 0;
	int max_size = 0;
    while(all[i] != NULL) {
        if(max_size < mx_strlen(all[i]->size_h)) {
            max_size = mx_strlen(all[i]->size_h);
        } 
        i++; 
    } 
    return max_size;   
}
