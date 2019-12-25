#include "uls.h"

char mx_get_acl(char *filename, char *path) {
    struct stat buff;
    char att;
    acl_t acl = NULL;
    ssize_t xattr = 0;

    lstat(path, &buff);
    acl = acl_get_file(filename, ACL_TYPE_EXTENDED);
    xattr = listxattr(filename, NULL, 0, XATTR_NOFOLLOW);
    if (xattr > 0)
        att = '@';
    else if (acl != NULL && ((buff.st_mode & S_IFMT) != S_IFLNK)) 
        att = '+';
    else
        att = ' ';
    acl_free(acl);
    return att;
}
