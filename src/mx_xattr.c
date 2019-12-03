#include "uls.h"

void mx_xattr(int *current_flags, t_file *all, t_file **all_f) {           
    if(current_flags[7]) { //-@
        if(all->acl_attr == '@') {
            ssize_t buflen;
            buflen = listxattr(all->path, NULL, 0, XATTR_SHOWCOMPRESSION);
            char *buf = malloc(buflen + 1);
            buflen = listxattr(all->path, buf, buflen, XATTR_SHOWCOMPRESSION);
            buf[buflen] = '\0';
            char *key = buf; 
            while (buflen > 0){
                mx_printchar('\t');
                mx_printstr(key);
                size_t vallen = getxattr(all->path, key, NULL, 0, 0, XATTR_SHOWCOMPRESSION);
                char *val = malloc(vallen + 1);
                size_t keylen = mx_strlen(key) + 1;
                vallen = getxattr(all->path, key, val, vallen, 0, XATTR_SHOWCOMPRESSION);
                val[vallen] = '\0';
                mx_printchar('\t');
                if(!current_flags[6]) { 
                    mx_space(mx_get_max_size(all_f) - 2);
                } else { //-h
                    mx_space(mx_get_max_size_h(all_f) - 2);
                }
                if(current_flags[6]) {// -h
                    char *size_h = mx_get_sizeh(mx_itoa(vallen));
                    mx_printstr(size_h);
                } else {
                    mx_printstr(mx_itoa(vallen));
                }
                mx_printstr(" ");
                mx_printstr("\n");
                free(val);
                buflen -= keylen;
                key += keylen;
            }
            free(buf);
        }
    } 
}
