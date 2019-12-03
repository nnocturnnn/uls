#include "libmx.h"

char *mx_itoa(int number) {
	long int m = number; 
	int c = 0;
	for(long i = m; i != 0; i /= 10){
		c++;
	}
	if(m < 0)
		c++;
	char *itoaaa = mx_strnew(c);
	if(number == 0)
		itoaaa[0] = '0';
	if(m < 0){
		itoaaa[0] = '-';
		m *= -1;
	}
	for(long i = m; i != 0; i /= 10){
		itoaaa[c-1] = i % 10 + 48;
		c--;
	}
	return itoaaa;
}
