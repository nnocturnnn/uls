#include "uls.h"

int mx_get_char_index_pr(const char *str, char c) {
	int i = 0;
	if(!str)
		return 0;
	else if(str[i] != '\0') {
		while(str[i]) {
			if(str[i] == c)
				return i;
			i++;
		}
	}
	return 0;
}
