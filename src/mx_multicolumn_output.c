#include "uls.h"

static int count_lines(int n_files, int max, int *cur_flag);
static char *get_path(char *File, char *Directory);
static int get_max_len(int *cur_flag, char **F, t_file **all, int n_files);
static int get_winsize();
static int get_max_space(int max, int *current_flags);

void mx_multicolumn_output(char **F, int n_files, int *cur_flag, char *Directory) {
    t_file **all = (t_file **)malloc(sizeof(t_file) * 200000);
    all = mx_get_fileinfo(all, F, Directory, cur_flag);
    int max = get_max_len(cur_flag, F, all, n_files);
    int count = count_lines(n_files, max, cur_flag);
    char *path;

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < n_files; j++) {
            if (j == i || (j - i) % count == 0) {
                path = get_path(F[j], Directory);
                mx_print_inode(all[j], all, cur_flag); // inode
                mx_printname_f(all[j], cur_flag);
                if (j + count >= n_files) {
                    mx_printstr("\n");
                } else {
                    mx_def_space(cur_flag, j, max, all);
                }
            }
        }
    }
    free(all);
}

static int count_lines(int n_files, int max, int *current_flags) {
    int win_col = get_winsize();//узнаем размер терминала
    int count = 1;// количество строк
    int space = get_max_space(max, current_flags);
    int c_words;// пробелы
    int add;

    if(n_files  * (max + space) >= win_col) {
        c_words = win_col / (max + space);
        if(c_words == 0) c_words++;
        add = 0;
        if((n_files % c_words) != 0) {
            add++;
        }
        count = (n_files / c_words) + add;
    }
    if(!n_files) 
        count = 0;
    return count;
}

static char *get_path(char *File, char *Directory) {
    char *path = malloc(sizeof(char *));
    path = mx_strjoin(path,Directory);
    path = mx_strjoin(path,"/");
    path = mx_strjoin(path,File);
    return path;
}

static int get_max_len(int *cur_flag, char **F, t_file **all, int n_files) {
    int max = 0;
    if(!cur_flag[12]) {
        for(int i= 0; i < n_files; i++) {
            if(mx_strlen(F[i]) > max) {
                max = mx_strlen(F[i]);
            }   
        }
    } else {// -i
        for(int i= 0; i < n_files; i++) {
            if(mx_strlen(F[i]) + mx_strlen(all[i]->inode) + 1 > max) {
                max = mx_strlen(F[i]) + mx_strlen(all[i]->inode) + 1;
            }
        }
    }
    return max;
}

static int get_winsize() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);//узнаем размер терминала
    int win_col = w.ws_col;

    return win_col;
}

static int get_max_space(int max, int *current_flags) {
    int tmp;
    int space;

    if(current_flags[2]) {// -G
        space = 1;
        return space;
    }
    tmp = max - 8;
    if(tmp < 0) { // if max len < 8
        space = 8 - max;
        return space;
    }
    while(tmp > 8) {
        tmp -= 8;
    }
    space = 8 - tmp;

    return space;
}

