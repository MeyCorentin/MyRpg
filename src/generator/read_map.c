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

int get_size(char *files_name, load_map_ *load_map)
{
    int fd = open(files_name, O_RDONLY);
    char buff[1];
    int len = 0;
    char *temp;
    char **tab;
    int test = 1;
    int check = 0;

    for (test = 1; test != 0; len++)
        test = read(fd, buff, 1);
    close(fd);
    temp = malloc(sizeof(char) * len);
    fd = open(files_name, O_RDONLY);
    read(fd, temp, len);
    temp[len + 1] = '\0';
    close(fd);
    load_map->full_file = temp;
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

int get_map(load_map_ *load_map)
{
    int k = load_map->x_size;
    int ok = 0;
    int check = 0;

    for (; load_map->full_file[k] != '\0'; k++) {
        (load_map->full_file[k] == '\n') ? my_putstr("\n") : 1;
        (load_map->full_file[k] == '[') ? ok = 1, k++ : 1;
        (load_map->full_file[k] == ']') ? ok = 0 : 1;
        if (ok == 1 && load_map->full_file[k] != '\n')
            my_putchar(load_map->full_file[k]);
    }
}
