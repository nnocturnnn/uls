#include "uls.h"

static char *okruglenie(char *rest_size);
static char *preobrazovanie(char *short_size, char *rest_size);
static char *recursion(char *short_size, int *count, char *sizes);

char *mx_get_short_size(int long_size, char *short_size,
                        int *count, char *sizes) {
    char *new_size = mx_itoa(long_size / 1024);
    char *rest_size = mx_itoa(long_size - mx_atoi(new_size) * 1024);

    if (long_size < 1024 && long_size > 999) 
        return "1.0K";
    rest_size = okruglenie(rest_size);
    short_size = mx_strjoin(short_size, new_size);
    short_size = preobrazovanie(short_size, rest_size);
    short_size = recursion(short_size, &*count, sizes);
    return short_size;
}

static char *okruglenie(char *rest_size) {
    while (mx_strlen(rest_size) < 4){
        char *tmp = rest_size;

        rest_size = "0";
        rest_size = mx_strjoin(rest_size, tmp);
    }
    for (int i = mx_strlen(rest_size) - 1; i > 1; i--) {
        if (rest_size[i] > 53 ) {// >5
            if (rest_size[i - 1] == 57 ) {// 9
                rest_size[i - 1] = '0';
                rest_size[i - 2]++;
            }
            else
                rest_size[i - 1]++; 
        }
    }
    return rest_size;
}

static char *preobrazovanie(char *short_size, char *rest_size) {
    if (mx_strlen(short_size) < 2) {
        if (rest_size[0] == 49) {
            short_size[mx_strlen(short_size) - 1]++;
            short_size = mx_strjoin(short_size, ".");
            short_size = mx_strjoin(short_size, "0");
        } 
        else {
            short_size = mx_strjoin(short_size, ".");
            short_size[mx_strlen(short_size)] = rest_size[1];
        }
    } 
    else
        if(mx_atoi(rest_size) > 1024/2) 
            short_size[mx_strlen(short_size) - 1]++;
    return short_size;
}

static char *recursion(char *short_size, int *count, char *sizes) {
    if (mx_atoi(short_size) / 1024 > 0) {
        (*count)++;
        short_size = mx_get_size_h(short_size);
    }
    for (int i = 0; i < mx_strlen(short_size); i++)
        if (mx_isalpha(short_size[i]))
            short_size[i] = '\0';
    short_size[mx_strlen(short_size)] = sizes[*count];
    return short_size;
}
