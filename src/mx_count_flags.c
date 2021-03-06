#include "uls.h"

static void check_flags(int i, char *argv[], char *flags, int *cur_flag);
static void no_allowed(char *flags, int i, int j, char *argv[]);

int mx_count_flags(int argc, char *argv[], char *flags, int *cur_flag) {
    int n_flags = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-' || !argv[i][1])
            break;
        if (argv[i][1] == '-' && !argv[i][2]){
            n_flags++;
            break;
        }
        n_flags++;
        check_flags(i, argv, flags, cur_flag);
    }
    return n_flags;
}

static void check_flags(int i, char *argv[], char *flags, int *cur_flag) {
    for (int j = 1; j < mx_strlen(argv[i]); j++) {
        bool allowed = 0;
        
        for (int k = 0; k < mx_strlen(flags); k++)
            if (argv[i][j] == flags[k] ) {
                allowed++;
                cur_flag[k] = 1;
            } 
        if (!allowed)
            no_allowed(flags, i, j, argv);
    }
}

static void no_allowed(char *flags, int i, int j, char *argv[]) {
    char *illegal = mx_strnew(1);
    char *flags_new = mx_sort_str(mx_strlen(flags), flags);

    mx_printerr("uls: illegal option -- ");
    illegal[0] = argv[i][j];
    mx_printerr(illegal);
    free(illegal);
    mx_printerr("\n");
    mx_printerr("usage uls [-");
    mx_printerr(flags_new);
    mx_printerr("] [file ...]");               
    mx_printerr("\n");
    exit(1);
}
