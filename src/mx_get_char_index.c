#include "uls.h"

int mx_get_char_index(const char *str, char c) {
    int res = -1;
    if(str == NULL) {
    	res = -2;
    	return res;
    }
    int len = 0;
    while(str[len]) {
    	if(str[len] == c){
    		res = len;
    		return res;
    	}
    	len++;
    }
    return res;
}
