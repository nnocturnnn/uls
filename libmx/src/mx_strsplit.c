#include "libmx.h"

 static int mx_strlendelim(const char *c, const char delim) {
    int i = 0;
    
    while (*c && *c++ != delim)
        i++;
    return i;
}

char **mx_strsplit(const char *s, char c) {
 	int i = 0;
 	int len = mx_count_words(s, c);
 	if(s == NULL) return NULL;
 	char **str = (char **) malloc(len * sizeof(char *));
 	while(*s) {
 		if(*s == c) {
 			s++;
 		}
 		else {
 			str[i] = mx_strnew(mx_strlendelim(s, c));
 			mx_strncpy(str[i], s, mx_strlendelim(s, c));
 		}
 		i++;
 	}
 	return str;
}
