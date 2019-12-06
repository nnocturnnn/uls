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
    	short_size = mx_get_short_size(long_size, short_size, &count, sizes);
    }
    return short_size;
}
