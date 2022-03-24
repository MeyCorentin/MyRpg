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
    #include "menu.h"

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
    int click;
    sfRectangleShape *rect;
    struct grid_cell *next_cell;
    struct grid_cell *prev_cell;
} grid_cell_;

typedef struct paint {
    int scale;
} paint_;

void init_rect(grid_cell_ *grid, sfRectangleShape *rect);
void create_map(game_ *game, struct grid_cell *grid, int x, int y);
void display_map(game_ *game, grid_cell_ *grid);
void launch_map_generator(game_ *game);
void moov_up(grid_cell_ *grid);
void moov_down(grid_cell_ *grid);
void moov_left(grid_cell_ *grid);
void moov_right(grid_cell_ *grid);
void moov_map(game_ *game, grid_cell_ *grid);
void map_key_input(game_ *game, grid_cell_ *grid);
void reset_grid(grid_cell_ *grid);
void right_click_grid(game_ *game, grid_cell_ *grid, paint_ *paint);
void left_click_grid(game_ *game, grid_cell_ *grid, paint_ *paint);
void map_mouse_input(game_ *game, grid_cell_ *grid, paint_ *paint);
void check_event_gen(game_ *game, gen_control_ *gen_control, paint_ *paint);

#endif /* !MAP_GRID_H_ */
