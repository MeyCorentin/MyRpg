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

void add_id_in_tab(char ***tab, char *id, int y, int x)
{
    int k = y;
    int j = x;
    int r = 0;

    for (; tab[k]; k++) {
        for (j = x; tab[k][j]; j++) {
            for (r = 0; id[r] != '\0'; r++) {
                tab[k][j][r] = id[r];
            }
            tab[k][j][r] = '\0';
        }
    }
}

char ***my_malloc_big_tab(int colum, int lines)
{
    char ***temp = malloc(sizeof(char *) * (colum + 1));
    int k = 0;
    int j = 0;

    for (; k != colum; k++) {
        temp[k] = malloc(sizeof(char *) * lines + 1);
        for (j = 0; j != lines; j++) {
            temp[k][j] = malloc(sizeof(char *) * 10);
        }
        temp[k][j] = '\0';
    }
    temp[k] = '\0';
    return (temp);
}

void display_big_tab(char ***map)
{
    int y = 0;
    int x = 0;
    for (y = 0; map[y]; y++) {
        for (x = 0; map[y][x]; x++) {
            my_putstr(map[y][x]);
            my_putstr("|");
        }
        my_putstr("\n");
    }
}

int get_map(load_map_ *load_map)
{
    int k = load_map->x_size;
    int ok = 0;
    int check = 0;
    int y = 0;
    int x = 0;
    char *temp = malloc(sizeof(char) * 1);
    char *temp_id = malloc(sizeof(char) * 20);
    char ***tileset_tab = my_malloc_big_tab(10, 5);

    temp_id[0] = '\0';
    for (; load_map->full_file[k] != '\0'; k++) {
        (load_map->full_file[k] == '\n') ? y++, x = 0 : 1;
        (load_map->full_file[k] == '[') ? ok = 1, k++ : 1;
        if (load_map->full_file[k] == ']') {
            ok = 0;
            add_id_in_tab(tileset_tab, temp_id, y, x);
            temp_id[0] = '\0';
            x++;
        }
        if (ok == 1 && load_map->full_file[k] != '\n') {
            temp[0] = load_map->full_file[k];
            temp[1] = '\0';
            temp_id = my_strcat(temp_id, temp);
        }
    }
    display_big_tab(tileset_tab);
}
