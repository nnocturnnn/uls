#include "uls.h"

static void get_f_controls(char **controls, char **new_controls, int number);
static void get_d_controls(char **controls, char **new_controls, int number);

char **mx_get_controls(t_file *all, char *str) {
    char **controls = mx_strsplit(str, ',');
    char **new_controls = (char **)malloc(sizeof(char *) * 200);

    for(int j = 0; j < 6; j++) {
        new_controls[j] = NULL;
    }
    int j = 0;
    while(controls[j] != NULL) {
        if(all->permissions[0] != 'd') {
            get_f_controls(controls, new_controls, j);
        } else {
            get_d_controls(controls, new_controls, j);
        }
        j++;
    }
    new_controls[j] = NULL;
    free(controls);
    return new_controls;
}

static void get_f_controls(char **controls, char **new_controls, int number) {
    char *file[] = {"read","write","execute","append"};

    for(int k = 0; k < 4; k++) {
        if(!mx_strcmp(controls[number],file[k])) {
            new_controls[number] = controls[number];
        }
    }
}

static void get_d_controls(char **controls, char **new_controls, int number) {
    char *file[] = {"read","write","execute","append"};
    char *directory[] = {"list","add_file","search","add_subdirectory","delete_child"};

    int flag = 0;
    for(int k = 0; k < 4; k++) {
        if(!mx_strcmp(controls[number],file[k])) {
            flag++;
            new_controls[number] = directory[k];        
        }
    }
    if(!flag) {
        new_controls[number] = controls[number];
    }
}


