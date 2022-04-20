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

void add_id_int_tab_2(char ***tab, char *id, int k, int j)
{
    int r = 0;

    for (; tab[k][j]; j++) {
        for (r = 0; id[r] != '\0'; r++) {
            tab[k][j][r] = id[r];
        }
        tab[k][j][r] = '\0';
    }
}

void add_id_in_tab(char ***tab, char *id, int y, int x)
{
    int k = y;
    int j = x;

    for (; tab[k]; k++) {
        add_id_int_tab_2(tab, id, k, j);
    }
}

char ***get_map(load_map_ *load_map)
{
    int k = load_map->x_size;
    int ok = 0;
    int y = 0;
    int x = 0;
    char *temp_id = malloc(sizeof(char) * 1000);
    char ***tile_tab = my_malloc_big_tab(load_map->y_size, load_map->x_size);

    temp_id[0] = '\0';
    for (; load_map->back_full[k] != '\0'; k++) {
        (load_map->back_full[k] == '\n') ? y++, x = 0 : 1;
        (load_map->back_full[k] == '[') ? ok = 1, k++ : 1;
        (load_map->back_full[k] == ']') ? ok = 0,
        add_id_in_tab(tile_tab, temp_id, y, x), temp_id[0] = '\0', x++ : 1;
        (ok == 1 && load_map->back_full[k] != '\n') ?
        temp_id = my_strcat_(temp_id, load_map->back_full[k]) : NULL;
    }
    return (tile_tab);
}

char ***get_map_2(load_map_ *load_map)
{
    int k = load_map->x_size;
    int ok = 0;
    int y = 0;
    int x = 0;
    char *temp_id = malloc(sizeof(char) * 1000);
    char ***tile_tab = my_malloc_big_tab(load_map->y_size, load_map->x_size);

    temp_id[0] = '\0';
    for (; load_map->fore_full[k] != '\0'; k++) {
        (load_map->fore_full[k] == '\n') ? y++, x = 0 : 1;
        (load_map->fore_full[k] == '[') ? ok = 1, k++ : 1;
        (load_map->fore_full[k] == ']') ? ok = 0,
        add_id_in_tab(tile_tab, temp_id, y, x), temp_id[0] = '\0', x++ : 1;
        (ok == 1 && load_map->fore_full[k] != '\n') ?
        temp_id = my_strcat_(temp_id, load_map->fore_full[k]) : NULL;
    }
    return (tile_tab);
}

char ***get_map_3(load_map_ *load_map)
{
    int k = load_map->x_size;
    int ok = 0;
    int y = 0;
    int x = 0;
    char *temp_id = malloc(sizeof(char) * 1000);
    char ***tile_tab = my_malloc_big_tab(load_map->y_size, load_map->x_size);

    temp_id[0] = '\0';
    for (; load_map->hit_full[k] != '\0'; k++) {
        (load_map->hit_full[k] == '\n') ? y++, x = 0 : 1;
        (load_map->hit_full[k] == '[') ? ok = 1, k++ : 1;
        (load_map->hit_full[k] == ']') ? ok = 0,
        add_id_in_tab(tile_tab, temp_id, y, x), temp_id[0] = '\0', x++ : 1;
        (ok == 1 && load_map->hit_full[k] != '\n') ?
        temp_id = my_strcat_(temp_id, load_map->hit_full[k]) : NULL;
    }
    return (tile_tab);
}
