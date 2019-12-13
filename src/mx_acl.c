#include "uls.h"

static char ***get_data(int count, acl_t acl);
static void print_all(char ***data, char **permissions, 
                                char **new_controls, int i);

void mx_acl(int *cur_flag, t_file *all) {
    struct stat buff; 

    lstat(all->path, &buff);         
    if(cur_flag[8] && ((buff.st_mode & S_IFMT) != S_IFLNK)) {// -e
        acl_t acl = acl_get_file(all->path, ACL_TYPE_EXTENDED);

        if(acl != NULL) {
            int count = mx_count_words(acl_to_text(acl, NULL), '\n');
            char ***data = get_data(count, acl);
            
            for (int i = 0; i < count  - 1; i++) {
                char **permissions = mx_strsplit(data[i][4], ',');
                char **new_controls = mx_get_controls(all, data[i][5]);

                print_all(data, permissions, new_controls, i);
            }
        }
        acl_free(acl);
     }
}

static char ***get_data(int count, acl_t acl) {
    char **arr  = mx_strsplit(acl_to_text(acl, NULL), '\n');
    char ***data = (char ***)malloc(sizeof(char **) * 200);

        for (int i = 1; i < count; i++) {
            //int count_w = mx_count_words(arr[i], ':');
            data[i - 1] = (char **)malloc(sizeof(char *) * 200);
            data[i - 1] = mx_strsplit(arr[i], ':');
        }
    data[count - 1] = NULL;
    return data;
}

static void print_all(char ***data, char **permissions, 
                                char **new_controls, int i) {
    mx_print_user(data, permissions, i);
    mx_prit_controls(new_controls);
    mx_prit_permisssions(permissions);
    mx_printstr("\n");
}


