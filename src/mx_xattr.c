#include "uls.h"

static char *get_list_xattr(t_file *file, ssize_t *buflen);
static void print_xattr(char *key, int vallen, t_file **all, int *cur_flag);

void mx_xattr(int *cur_flag, t_file *file, t_file **all) {           
    if(cur_flag[7]) { //-@
        if(file->acl_attr == '@') {
            ssize_t buflen;
            char *key = get_list_xattr(file, &buflen);

            while (buflen > 0) {
                size_t vallen = getxattr(file->path, key, NULL,
                                         0, 0, XATTR_SHOWCOMPRESSION);
                size_t keylen = mx_strlen(key) + 1;

                print_xattr(key, vallen, all, cur_flag);
                buflen -= keylen;
                key += keylen;
            }
        }
    } 
}

static char *get_list_xattr(t_file *file, ssize_t *buflen) {
    char *buf;

    *buflen = listxattr(file->path, NULL, 0, XATTR_SHOWCOMPRESSION);
    buf = malloc(*buflen + 1);
    *buflen = listxattr(file->path, buf, *buflen, XATTR_SHOWCOMPRESSION);
    buf[*buflen] = '\0';
    return buf;
}

static void print_xattr(char *key, int vallen, t_file **all, int *cur_flag) {
    mx_printchar('\t');
    mx_printstr(key);
    mx_printchar('\t');
    if(!cur_flag[6]) { // standart output
        mx_space(mx_get_max_size(all) - 2);
        mx_printstr(mx_itoa(vallen));
    } else { //-h
        mx_space(mx_get_max_size_h(all) - 2);
        mx_printstr(mx_get_sizeh(mx_itoa(vallen)));
    }
    mx_space(1);
    mx_printstr("\n");
}
