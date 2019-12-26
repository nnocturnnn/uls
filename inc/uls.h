#ifndef ULS_H
#define ULS_H

#include <stdio.h>
#include <wchar.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <malloc/malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include <sys/acl.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <sys/acl.h>
#include <sys/xattr.h>
#include <time.h>
#include "libmx/inc/libmx.h"

typedef struct s_file {
    char *path;
    char *filename;
    char *size;
    char *size_h;
    char *owner; 
    char *short_time;
    char *full_time; 
    char *permissions; 
    char *links; 
    char *group;
    char *inode;  
    char *blksize;
    char *blocks;
    char acl_attr;
} t_file;

typedef struct s_all  {
    int n_flags;
    int n_errors;
    int n_files;
    int n_dirs;
    int *priority;
} t_all;


typedef struct s_arr {
    char **F;
    char **D;
    char **E;
} t_arr;



int mx_atoi(const char *str);
bool mx_isspace(char c);
char *mx_strcat(char *restrict s1, const char *restrict s2);
int mx_strlen(const char *s);
char *mx_itoa(int number);
int mx_strcmp(const char *s1, const char *s2);
void mx_del_strarr(char ***arr);
void mx_printchar(char c);
char *mx_strcpy(char *dst, const char *src);
char *mx_strndup(const char *s1, size_t n);
char *mx_file_to_str(const char *file);
void mx_printerr(const char *s);
void mx_strdel(char **str);
char *mx_strnew(const int size);
int mx_get_char_index(const char *str, char c);
void mx_printint(int n);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
bool mx_isdigit(int c);
void mx_printstr(const char *s);
char *mx_strjoin(const char *s1, const char *s2);
bool mx_isalpha(int c);



int mx_count_flags(int argc, char *argv[], char *flags, int *cur_flag);//c
//schitivaem kolichestvo -l -- и за одно ошибка на флаг если есть
int mx_fill_errors(int argc, char *argv[], int n_flags, char **E);
//если файла из аргв нет возврщаем масив с не известными файлами
int mx_fill_files(int argc, char *argv[], int n_flags, char **F);
//через гет пермисион провереям с инпута на файл или нет и заполняем если файл
int mx_fill_dirs(int argc, char *argv[], int n_flags, char **D);
//такое же как файлс только чекаем на директорию
char *mx_get_permissions(struct stat file_stat);
//берем и возращаем его дрв-рв-рв
char *mx_strncpy(char *dst, const char *src, int len);

void mx_cat_output(char **F, int *cur_flag, char *Directory);
//output with | cat
void mx_multicolumn_output(char **F,int n_files, int *cur_flag,
                                                     char *Directory);
//default output
void mx_long_output(char **F, int *cur_flag, char *Directory);
//-l
char *mx_get_group(struct stat buff, int *cur_flag);
//lorem ipsum
char *mx_get_owner(struct stat buff, int *cur_flag);
//return access control list + mbashenko , spshenchn ili eto eto delaet
t_file **mx_get_fileinfo(t_file **all, char **F, 
                            char *Directory, int *cur_flag);
//get all info about file
int mx_get_max_size(t_file **all);
int mx_get_max_links(t_file **all);
int mx_get_max_owner(t_file **all);
int mx_get_max_group(t_file **all);
int mx_get_max_time(t_file **all);
//kakieto huini dlia xattra
char *mx_get_full_time(time_t time);
//return last update time
char *mx_get_size_h(char *size);
//size with gb kb b tb
void mx_is_allowed(char *Directory);
//check access in dirs hz kak
char **mx_read(int *cur_flag, DIR *dptr, int *dir_count);
// read all in directory
void mx_R(int *cur_flag, char **F, t_all all, char *Directory, int dir_count);
//R
void mx_space(int count);
char mx_get_acl(char *filename, char *path);
//return access control list + mbashenko , spshenchn huinia kakaito
void mx_get_total(char **F, char *Directory);
//print total in l on start of output what is mean size on pc magic lang
void mx_print_abcents(t_all all, char **E);
//в зависимости от ошибок выводим по порядку ошибки
void mx_print_files(t_all all, char **F,  int *cur_flag);
//печатаем необходимые файлы !!!!!!!!!
void mx_print_dirs(t_all all, char **D, int *cur_flag);
//print dirs
void mx_print_dname(int n_dirs, int n_files, int n_errors, char *dname);
//print names of dirs if in input more then 2 or in R
char *mx_strchr(const char *s, int c);
void mx_printname_f(t_file *file, int *cur_flag);
//output files and dirs with -G if needed
void mx_xattr(int *cur_flag, t_file *all, t_file **all_f);
//huinia kakaiato
char *mx_sort_str(int len, char *str);
//XD
char *mx_sizetoa(size_t number);
char *mx_get_short_time(time_t time,  time_t current_time);
//return short time last change
void mx_acl(int *cur_flag, t_file *all);
int *mx_get_current_flags(char *flags);
//get array 0000000000000000 length flags in program
void mx_backsorty(char **arr, int left, int right);
//если -р возвращаем назад файлы по алфавиту как в квик сорте
char *mx_get_short_size(int long_size, char *short_size, 
                        int *count, char *sizes);
//hz kakoi short size
void mx_def_space(int *cur_flag, int j, int max, t_file **all);
// get ' ' between files
void mx_1_output(char **F, int *cur_flag, char *Directory);
//like with cat but it 1
void mx_print_user(char ***data, char **permissions, int number);
//logic
void mx_print_permissions(char **permissions);
//r-wx-xyi
void mx_print_controls(char **new_controls);
char **mx_get_controls(t_file *all, char *str);
void mx_print_inode(t_file *file, t_file **all, int *current_flags);
//-i

void mx_flong_out(t_file **all, int i, int *cur_flag);
//in l first part
void mx_slong_out(t_file **all, int i, int *cur_flag);
//second part l
void mx_checksort(char **F, int *cur_flag, int dir_count);
//check on how sort normalna or with -r
char *mx_get_size(struct stat buff,  int *cur_flag);
//return size in bits
int *mx_priority(char *flags, char **argv, int argc);
//в зависимости от ласт флага определяем приоритет
void mx_m_output(char **F, int *cur_flag, char *Directory);
//with ,
void mx_sorty(t_arr arr, t_all all, int *cur_flag);
//сортируем по алфавиту

#endif 
