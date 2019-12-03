#include "uls.h"

static int count_lines(int n_files, int max, int *current_flags);
static char *get_path(char *File, char *Directory);
static int get_max_len(int *current_flags, char **F, t_file **all, int n_files);
static void print_inode(t_file *all, int *current_flags);

void mx_multicolumn_output(char **F, int n_files, int *current_flags, char *Directory) {
    t_file **all = (t_file **)malloc(sizeof(t_file) * 200);
    all = mx_get_fileinfo(all, F, Directory, current_flags);
    int max = get_max_len(current_flags, F, all, n_files);
    int count = count_lines(n_files, max, current_flags);
    for(int i = 0; i < count; i++) {
        for(int j = 0; j < n_files; j++) {
            if (j == i || (j - i) % count == 0) {
                char *path = get_path(F[j], Directory);
                print_inode(all[i], current_flags); // inode
                mx_printname_f(path, current_flags);
                if(!current_flags[12]){ // standart(without inode)
                    mx_space(max - mx_strlen(F[j]));
                    if(current_flags[2]) {// -G
                        mx_space(1);
                    } else { // standart output
                        mx_printstr("\t");
                    }
                } else { // -i
                    mx_space(max - (mx_strlen(F[j]) + mx_strlen(all[j]->inode)));
                }
            }
        }
        if(count){
            mx_printstr("\n");
        }
    }
    free(all);
}

static int count_lines(int n_files, int max, int *current_flags) {
	struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);//узнаем размер терминала
	int w1 = w.ws_col; 
    int count = 1;
    int tmp = max;
    while(tmp >= 9) {
        tmp -= 8;
    }
    int space = 9 - tmp;
    if(current_flags[2]) {// -G
        space = 1;
    }
    if(n_files  * (max + space) >= w1) {
        int c_words = w1 / (max + space);
        int add = 0;
        if((n_files % c_words) != 0) {
            add++;
        }
        count = (n_files / c_words) + add;
    }
    if(!n_files) count = 0;
    return count;
}

static char *get_path(char *File, char *Directory) {
    char *path = malloc(sizeof(char *));
    path = mx_strjoin(path,Directory);
    path = mx_strjoin(path,"/");
    path = mx_strjoin(path,File);
    return path;
}

static int get_max_len(int *current_flags, char **F, t_file **all, int n_files) {
    int max = 0;
    if(!current_flags[12]) {
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

static void print_inode(t_file *all, int *current_flags) {
    if(current_flags[12]) { // -i
        mx_printstr(all->inode);
        mx_printstr(" ");
    }
}

