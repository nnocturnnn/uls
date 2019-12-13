#include "uls.h"

static char *nbr_to_hex(unsigned long nbr);

char *mx_get_size(struct stat buff, int *cur_flag) {
    char *size = mx_strnew(30);
    char *permissions = mx_get_permissions(buff);
    char *major = mx_itoa((buff.st_rdev >> 24) & 0xff);
    char *minor = mx_itoa(buff.st_rdev & 0xffffff);

    if((buff.st_rdev & 0xffffff) > 999) {
        minor =  nbr_to_hex(buff.st_rdev & 0xffffff);
        while (mx_strlen(minor) < 10) {
            minor = mx_strjoin("0", minor);
        }
        minor[1] = 'x';
    } 
    while (mx_strlen(major) < 3) {
        major = mx_strjoin(" ", major);
    }
    while (mx_strlen(minor) < 3) {
        minor = mx_strjoin(" ", minor);
    }

    if ((permissions[0] == 'c' || permissions[0] == 'b')) {
        size = mx_strjoin(size, major);
        size = mx_strjoin(size, ", ");
        size = mx_strjoin(size, minor);
    } else {
        if(cur_flag[6]) {
            size = mx_get_sizeh(mx_sizetoa(buff.st_size));
        } else {
            size = mx_sizetoa(buff.st_size);
        }
    }
    return size;
}

static char *nbr_to_hex(unsigned long nbr) {
    unsigned long tmp_nbr = nbr;
    int len = 0;
    while(tmp_nbr > 1) {
        tmp_nbr /= 16;
        len++;
    }
    char *string = mx_strnew(len);
    len = 0;
    int c;
    while (nbr) {
        c = nbr % 16;
        nbr /= 16;
        if (c < 10) {
            string[len] = c + 48;
        }
        else {
            string[len] = c + 87;
        }
        len++;
    }
    int i;
    for( i = 0;i < len / 2; i++){
        char tmp;
        tmp = string[i];
        string[i] = string[len - i - 1];
        string[len - i - 1] = tmp;
    }

    return string;
}
