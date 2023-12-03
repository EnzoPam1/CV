/*
** EPITECH PROJECT, 2023
** B-PSU-100-NCY-1-1-myls-enzo.pambout
** File description:
** file_details
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "../include/my.h"

static char *get_permissions(mode_t mode)
{
    static char perms[11];

    perms[0] = (S_ISDIR(mode)) ? 'd' : '-';
    perms[1] = (mode & S_IRUSR) ? 'r' : '-';
    perms[2] = (mode & S_IWUSR) ? 'w' : '-';
    perms[3] = (mode & S_IXUSR) ? 'x' : '-';
    perms[4] = (mode & S_IRGRP) ? 'r' : '-';
    perms[5] = (mode & S_IWGRP) ? 'w' : '-';
    perms[6] = (mode & S_IXGRP) ? 'x' : '-';
    perms[7] = (mode & S_IROTH) ? 'r' : '-';
    perms[8] = (mode & S_IWOTH) ? 'w' : '-';
    perms[9] = (mode & S_IXOTH) ? 'x' : '-';
    perms[10] = '\0';
    return perms;
}

void print_stat_details(const struct stat *file_stat)
{
    char *time_str = ctime(&file_stat->st_mtime);

    my_putstr(get_permissions(file_stat->st_mode));
    my_putchar(' ');
    print_number_with_padding((unsigned long)file_stat->st_nlink, 3);
    my_putchar(' ');
    print_file_owner_group(file_stat);
    my_putchar(' ');
    print_long_with_padding((long)file_stat->st_size, 5);
    my_putchar(' ');
    my_putstr(time_str);
    my_putchar(' ');
}

void print_file_owner_group(const struct stat *file_stat)
{
    my_putstr(getpwuid(file_stat->st_uid)->pw_name);
    my_putchar(' ');
    my_putstr(getgrgid(file_stat->st_gid)->gr_name);
}

void print_file_details(const char *file_name)
{
    struct stat file_stat;

    if (stat(file_name, &file_stat) == -1) {
        perror("stat");
        return;
    }
    print_stat_details(&file_stat);
    my_putstr(file_name);
    my_putchar('\n');
}
