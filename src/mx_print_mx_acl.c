#include "uls.h"

static void prit_permisssions(char **permissions);
static void prit_controls(char **new_controls);
static char **get_controls(char **controls, t_file *all);

void mx_print_mx_acl(char ***data, t_file *all, int i) {
    char **permissions;
    char **controls;
    char **new_controls;

    mx_printstr(" ");
    mx_printstr(mx_itoa(i));
    mx_printstr(": ");
    mx_printstr(data[i][0]);
    mx_printstr(":");
    mx_printstr(data[i][2]);
    mx_printstr(" ");
    permissions = mx_strsplit(data[i][4], ',');
    mx_printstr(permissions[0]);
    mx_printstr(" ");
    controls = mx_strsplit(data[i][5], ',');
    new_controls = get_controls(controls, all);
    prit_controls(new_controls);
    prit_permisssions(permissions);
    mx_printstr("\n");
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
    char *directory[] = {"list","add_file","search",
                        "add_subdirectory","delete_child"};
    char **new_controls = (char **)malloc(sizeof(char *) * 200);
    int j = 0;

    for(int k = 0; k < 6; k++) {
        new_controls[j] = NULL;
    }
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
