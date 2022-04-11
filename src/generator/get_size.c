/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** read_map
*/

#include "../../includes/rpg.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_file_len(char *files_name)
{
    int len = 0;
    char buff[1];
    int test = 1;

    int fd = open(files_name, O_RDONLY);
    for (test = 1; test != 0; len++)
        test = read(fd, buff, 1);
    close(fd);
    return (len);
}

int get_size(char *files_name, load_map_ *load_map)
{
    int len = get_file_len(files_name);
    char *temp = malloc(sizeof(char) * len);
    char **tab;
    int check = 0;
    int fd = open(files_name, O_RDONLY);
    int test;

    read(fd, temp, len);
    temp[len + 1] = '\0';
    close(fd);
    load_map->back_full = temp;
    tab = my_split_tab(temp, '\n');
    temp = malloc(sizeof(char) * my_strlen(tab[0]));
    for (test = 0, len = 0; tab[0][len] != 0; len++) {
        (check == 1) ? temp[test] = tab[0][len], test++ : 1;
        (tab[0][len] == ' ') ? check = 1 : 1;
    }
    temp[test + 1] = '\0';
    load_map->y_size = my_atoi(tab[0]);
    load_map->x_size = my_atoi(temp);
}

int get_size_2(char *files_name, load_map_ *load_map)
{
    int len = get_file_len(files_name);
    char *temp = malloc(sizeof(char) * len);
    char **tab;
    int check = 0;
    int fd = open(files_name, O_RDONLY);
    int test;

    read(fd, temp, len);
    temp[len + 1] = '\0';
    close(fd);
    load_map->fore_full = temp;
    tab = my_split_tab(temp, '\n');
    temp = malloc(sizeof(char) * my_strlen(tab[0]));
    for (test = 0, len = 0; tab[0][len] != 0; len++) {
        (check == 1) ? temp[test] = tab[0][len], test++ : 1;
        (tab[0][len] == ' ') ? check = 1 : 1;
    }
    temp[test + 1] = '\0';
    load_map->y_size = my_atoi(tab[0]);
    load_map->x_size = my_atoi(temp);
}

int get_size_3(char *files_name, load_map_ *load_map)
{
    int len = get_file_len(files_name);
    char *temp = malloc(sizeof(char) * len);
    char **tab;
    int check = 0;
    int fd = open(files_name, O_RDONLY);
    int test;

    read(fd, temp, len);
    temp[len + 1] = '\0';
    close(fd);
    load_map->hit_full = temp;
    tab = my_split_tab(temp, '\n');
    temp = malloc(sizeof(char) * my_strlen(tab[0]));
    for (test = 0, len = 0; tab[0][len] != 0; len++) {
        (check == 1) ? temp[test] = tab[0][len], test++ : 1;
        (tab[0][len] == ' ') ? check = 1 : 1;
    }
    temp[test + 1] = '\0';
    load_map->y_size = my_atoi(tab[0]);
    load_map->x_size = my_atoi(temp);
}
