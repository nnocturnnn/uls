#include "uls.h"

static char ***get_data(int count, char **arr);
static void prit_permisssions(char **permissions);
static void prit_controls(char **new_controls);
static char **get_controls(char **controls, t_file *all);

void mx_acl(int *current_flags, t_file *all) {            
    if(current_flags[8] && all->permissions[0] != 'l') {// -e
        acl_t acl = acl_get_file(all->path, ACL_TYPE_EXTENDED);

        if(acl != NULL) {
            int count = mx_count_words(acl_to_text(acl, NULL), '\n');
            char **arr  = mx_strsplit(acl_to_text(acl, NULL), '\n');
            char ***data = get_data(count, arr);
            
            for (int i = 0; i < count  - 1; i++) {
                mx_printstr(" ");
                mx_printstr(mx_itoa(i));
                mx_printstr(": ");
                mx_printstr(data[i][0]);
                mx_printstr(":");
                mx_printstr(data[i][2]);
                mx_printstr(" ");
                char **permissions = mx_strsplit(data[i][4], ',');
                mx_printstr(permissions[0]);
                mx_printstr(" ");
                char **controls = mx_strsplit(data[i][5], ',');
                char **new_controls = get_controls(controls, all);
                prit_controls(new_controls);
                prit_permisssions(permissions);
                mx_printstr("\n");
                free(new_controls);
                free(controls);
                free(permissions);   
            }
        }
        acl_free(acl);
    }
}

static char ***get_data(int count, char **arr) {
    char ***data = (char ***)malloc(sizeof(char **) * 200);
        for (int i = 1; i < count; i++) {
            //int count_w = mx_count_words(arr[i], ':');
            data[i - 1] = (char **)malloc(sizeof(char *) * 200);
            data[i - 1] = mx_strsplit(arr[i], ':');
        }
    data[count - 1] = NULL;
    return data;
}

static void prit_permisssions(char **permissions) {
    int j = 1;
    while(permissions[j]) {
        mx_printstr(",");
        mx_printstr(permissions[j]);
        j++;
    }
}

static void prit_controls(char **new_controls) {
    int j = 0;
    while(new_controls[j] != NULL) {
        mx_printstr(new_controls[j]);
        if(new_controls[j + 1] != NULL) {
            mx_printchar(',');
        }
        j++;
    }
}

static char **get_controls(char **controls, t_file *all) {
    char *file[] = {"read","write","execute","append"};
    char *directory[] = {"list","add_file","search","add_subdirectory","delete_child"};
    char **new_controls = (char **)malloc(sizeof(char *) * 200);

    for(int j = 0; j < 6; j++) {
        new_controls[j] = NULL;
    }
    int j = 0;
    while(controls[j] != NULL) {
        if(all->permissions[0] != 'd') {
            for(int k = 0; k < 5; k++) {
                if(!mx_strcmp(controls[j],file[k])) {
                    new_controls[j] = controls[j];
                }
            }
        } else {
            int flag = 0;
            for(int k = 0; k < 5; k++) {
                if(!mx_strcmp(controls[j],file[k])) {
                    flag++;
                    new_controls[j] = directory[k];        
                }
            }
            if(!flag) {
                new_controls[j] = controls[j];
            }
        }
        j++;
    }
    new_controls[j] = NULL;
    return new_controls;
}




