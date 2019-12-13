#include "uls.h"

static int get_winsize();
static int  mx_namelen(t_file *file);

void mx_m_output(char **F, int *cur_flag, char *Directory) {
    t_file **all = (t_file **)malloc(sizeof(t_file) * 200000);
    all = mx_get_fileinfo(all, F, Directory, cur_flag);
    int i = 0;
    int size = 0;
    int c_len = 0;
    int win = get_winsize();

    while(F[size] != NULL) {
        size++;
    }
    while(F[i] != NULL) {
        if(cur_flag[12]) {
            c_len += mx_namelen(all[i]) + 9;
        } else {
            c_len += mx_namelen(all[i]) + 2;
        }
        if(cur_flag[12] && c_len < win) { // -i
            mx_printstr(all[i]->inode);
            mx_printstr(" ");
        }
        if(c_len < win) {
            mx_printname_f(all[i], cur_flag);
            if(i < size - 1)
                mx_printstr(", ");
            else
                mx_printstr("\n");
            i++;
        } else {
            mx_printstr("\n");
            c_len = 0;
        }
    }
}

static int get_winsize() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);//узнаем размер терминала
    int win_col = w.ws_col;

    return win_col;
}

static int  mx_namelen(t_file *file) {
    int q;

    q = mx_strlen(file->filename);
    return q;
}
