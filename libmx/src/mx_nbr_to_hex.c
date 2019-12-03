#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    int i = 0; int s = 0;int count = 0;
    unsigned long q = nbr;
    while(q != 0){
    	q /=  16;
    	count++;
    }
    char *hex = mx_strnew(count);
    char *qhex = mx_strnew(count);
    if(nbr == 0)
    	qhex[0] = '0';
    while(nbr != 0) 
    {    
        int temp  = 0; 
        temp = nbr % 16; 
        if(temp < 10) 
        { 
            hex[i] = temp + 48; 
            i++; 
        } 
        else
        { 
            hex[i] = temp + 87; 
            i++; 
        } 
          
        nbr /= 16; 
    }
    for(;count > 0; count--) {
    	qhex[s] = hex[count-1];
    	s++;
    }
    return qhex;
}
