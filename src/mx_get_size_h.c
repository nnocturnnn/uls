#include "uls.h"

char *mx_get_sizeh(char *size) {
	char *sizes = {"BKMGT\0"};
	static int count = 1;
    int long_size = mx_atoi(size);
    char *short_size = mx_strnew(4);
    if(mx_strlen(size) <= 3) {
    	short_size = mx_strcpy(short_size, size);
    	short_size[mx_strlen(short_size)] = 'B';
    	return short_size;
    } else {
    	char *new_size = mx_itoa(long_size / 1024);
    	if(long_size < 1024 && long_size > 999) {
    		return "1.0K";
    	}
    	char *rest_size = mx_itoa(long_size - mx_atoi(new_size) * 1024);
    	while(mx_strlen(rest_size) < 3){
    		char *tmp = rest_size;
    		rest_size = "0";
    		rest_size = mx_strjoin(rest_size, tmp);
    	}
    	for(int i = mx_strlen(rest_size - 1); i > 0; i--) {
    		if(rest_size[i] >= 53) {
    		rest_size[i - 1]++;
    		}
    	}
    	short_size = mx_strjoin(short_size, new_size);
    	if(mx_strlen(short_size) < 2) {
    		short_size = mx_strjoin(short_size, ".");
    		short_size[mx_strlen(short_size)] = rest_size[0];
    	} else {
    		if(rest_size[0] >= 53 ) {
    			short_size[mx_strlen(short_size) - 1]++;
    		}
    	}
    	if(mx_atoi(short_size) / 1024 > 0) {
    		count++;
    		short_size = mx_get_sizeh(short_size);
    	}
    }
    int i = mx_strlen(short_size) - 1;
    while(mx_isalpha(short_size[i])) {
    	short_size[i] = '\0';
    	i++;
    }
    short_size[mx_strlen(short_size)] = sizes[count];
    return short_size;
}
