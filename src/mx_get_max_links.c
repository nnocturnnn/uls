#include "uls.h"

int mx_get_max_links(t_file **all) {
	int i = 0;
	int max_size = 0;
    while(all[i] != NULL) {
        if(max_size < mx_strlen(all[i]->links)) {
            max_size = mx_strlen(all[i]->links);
        } 
        i++; 
    } 
    return max_size;   
}
