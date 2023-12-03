/*
** EPITECH PROJECT, 2023
** Day09
** File description:
** task02
*/

#ifndef MY_H
    #include <stdbool.h>
    #include <stddef.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #define MY_H

typedef struct s_word_params {
    char **words;
    const char *str;
    int start;
    int index;
} t_word_params;

typedef struct s_options {
    bool list_long;
    bool recursive;
    bool sort_time;
    bool reverse;
    bool all;
    bool error_flag;
    bool directory_only;
} t_options;

typedef struct {
    t_options opts;
    char **files;
    int file_count;
} parsed_args;

int my_compute_power_it(int, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int);
int my_isalnum(int);
int my_isalpha(int);
int my_isneg(int);
int my_isnum(int);
int my_isprint(int);
int my_isupper(int);
void my_put_nbr(int);
void my_putchar(char);
int my_putnbr_base(unsigned int, char const *);
int my_putstr(char const *str);
char *my_revstr(char);
int my_showstr(char const *str);
void my_sort_int_array(int, int);
char *my_strcapitalize(char);
char *my_strcat(char, char const);
char *my_strcpy(char, char const);
int my_str_isalpha(char const);
int my_str_islower(char const);
int my_str_isnum(char const);
int my_str_isprintable(char const);
int my_str_isupper(char const);
int my_strlen(char const *);
char *my_strlowcase(char);
char *my_strncat(char, char const, int);
int my_strncmp(char const, char const, int);
char *my_strncpy(char, char const, int);
char *my_strstr(char, char const);
char *my_strupcase(char);
void my_swap(int, int);
int my_showmem(char const *str, int size);
int my_getnbr_base(char const *str, char const *base);
int my_index_of(char const *str, char c);
char **my_str_to_word_array(char const *str);
int fill_words_array(char **words, const char *str);
char *duplicate_word(const char *str, int start, int end);
int is_word_char(char c);
void list_directory_long(const t_options *options, const char *path);
t_options default_options(void);
parsed_args parse_arguments(int argc, char **argv);
void sort_files_by_time(struct dirent ***file_list, int *count,
    const char *dir_name);
void list_directory_recursive(const char *dir_name, const t_options *options);
void list_directory_sort_time(const t_options *options, const char *path);
void print_number_with_padding(int number, int field_width);
void print_long_with_padding(long number, int field_width);
void my_put_long(long nb);
char *my_strcat_with_slash(char *dest, const char *src1, const char *src2);
void my_putstr_err(const char *str);
void print_file_details(const char *file_name);
void print_stat_details(const struct stat *file_stat);
void print_file_owner_group(const struct stat *file_stat);
void process_file_list(struct dirent **file_list, int count,
    const t_options *options);
void free_file_list(struct dirent **file_list, int count);
void execute_ls_options(const t_options *options, const char *path);
void list_directory(const t_options *options, const char *path);
int my_strcmp(const char *s1, const char *s2);

#endif /* MY_H */
