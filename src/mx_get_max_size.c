#include "uls.h"

int mx_get_max_size(t_file **all) {
	int i = 0;
	int max_size = 0;
    while (all[i] != NULL) {
        if (max_size < mx_strlen(all[i]->size)) {
        	if (mx_get_char_index(all[i]->size, ',') > 0) {
        		if (max_size <= 8) {
        			max_size = 8;
        		}
        	} else {
            	max_size = mx_strlen(all[i]->size);
        	}
        } 
        i++; 
    } 
    return max_size;   
}
