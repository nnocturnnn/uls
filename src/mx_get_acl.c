#include "uls.h"

char mx_get_acl(char *filename) {
    char att;
    acl_t acl = NULL;
    ssize_t xattr = 0;
    acl = acl_get_file(filename, ACL_TYPE_EXTENDED);
    xattr = listxattr(filename, NULL, 0, XATTR_NOFOLLOW);
    if (xattr > 0){
        att = '@';
    } else if (acl != NULL) {
        att = '+';
    } else {
        att = ' ';
    } 
    acl_free(acl);
    return att;
}
