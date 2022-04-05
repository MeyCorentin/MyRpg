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
    int size_x;
    int size_y;
    int size;
    int l_pos;
    int g_pos;
    int ground;
    int hitbox;
    int click;
    int foreground_id;
    int background_id;
    int is_sprite;
    sfRectangleShape *rect;
    struct grid_cell *next_cell;
    struct grid_cell *prev_cell;
    struct sprite *foreground;
    struct sprite *background;
} grid_cell_;

typedef struct paint {
    int scale;
} paint_;

void init_rect(grid_cell_ *grid, sfRectangleShape *rect, int x, int y);
void create_map(game_ *game, struct grid_cell *grid, int x, int y);
void display_square(game_ *game, grid_cell_ *grid,
gen_control_ *gen_control, paint_ *paint);
void display_foreground(game_ *game, grid_cell_ *grid,
gen_control_ *gen_control, paint_ *paint);

void launch_map_generator(game_ *game);
void moov_up(grid_cell_ *grid);
void moov_down(grid_cell_ *grid);
void moov_left(grid_cell_ *grid);
void moov_right(grid_cell_ *grid);
void moov_map(game_ *game, grid_cell_ *grid);
void map_key_input(game_ *game, grid_cell_ *grid, gen_control_ *gen_control);
void reset_grid(grid_cell_ *grid);
void right_click_grid(game_ *game, grid_cell_ *grid,
paint_ *paint, gen_control_ *gen_control);
void left_click_grid(game_ *game, grid_cell_ *grid,
paint_ *paint, gen_control_ *gen_control);
void map_mouse_input(game_ *game, grid_cell_ *grid,
paint_ *paint, gen_control_ *gen_control);
void check_event_gen(game_ *game, gen_control_ *gen_control, paint_ *paint);
void display_all(game_ *game, grid_cell_ *grid,
gen_control_ *gen_control, paint_ *paint);
void save_foreground(game_ *game, grid_cell_ *grid, FILE *file);
void save_background(game_ *game, grid_cell_ *grid, FILE *file);
void draw_ath(game_ *game, gen_control_ *gen_control);
void moov_up_gen(sprite_ *sprite);
void moov_down_gen(sprite_ *sprite);
void moov_right_gen(sprite_ *sprite);
void moov_left_gen(sprite_ *sprite);
int get_size(char *files_name, load_map_ *load_map);
int get_map(load_map_ *load_map);

#endif /* !MAP_GRID_H_ */
