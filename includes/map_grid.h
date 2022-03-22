/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** map_grid
*/

#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>

#ifndef MAP_GRID_H_
    #define MAP_GRID_H_

    #include "rpg.h"

typedef struct grid_cell {
    int x;
    int y;
    int pos_x;
    int pos_y;
    int size;
    int l_pos;
    int g_pos;
    int ground;
    int sprite;
    int hitbox;
    sfRectangleShape *rect;
    struct grid_cell *next_cell;
    struct grid_cell *prev_cell;
} grid_cell_;

void init_rect(grid_cell_ *grid, sfRectangleShape *rect);
void create_map(game_ *game, struct grid_cell *grid, int x, int y);
void display_map(game_ *game, grid_cell_ *grid);
void launch_map_generator(game_ *game);
#endif /* !MAP_GRID_H_ */
