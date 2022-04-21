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

void init_rect(grid_cell_ *grid, sfRectangleShape *rect, int x, int y);
int create_map(game_ *game, struct grid_cell *grid, int x, int y);
void display_square(game_ *game, grid_cell_ *grid,
gen_control_ *gen_control, paint_ *paint);
void launch_map_generator(game_ *game);
int moov_up(grid_cell_ *grid);
int moov_down(grid_cell_ *grid);
int moov_left(grid_cell_ *grid);
int moov_right(grid_cell_ *grid);
void moov_map(game_ *game, grid_cell_ *grid);
int map_key_input(game_ *game, grid_cell_ *grid);
int reset_grid(grid_cell_ *grid);
void right_click_grid(game_ *game, grid_cell_ *grid,
paint_ *paint, gen_control_ *gen_control);
void left_click_grid(game_ *game, grid_cell_ *grid,paint_ *paint);
void map_mouse_input(game_ *game, grid_cell_ *grid, paint_ *paint);
void check_event_gen(game_ *game, paint_ *paint);
void display_all(game_ *game, grid_cell_ *grid, paint_ *paint);
void save_foreground(game_ *game, grid_cell_ *grid, FILE *file);
void save_background(game_ *game, grid_cell_ *grid, FILE *file);
void draw_ath(game_ *game);
int moov_up_gen(sprite_ *sprite);
int moov_down_gen(sprite_ *sprite);
int moov_right_gen(sprite_ *sprite);
int moov_left_gen(sprite_ *sprite);
void get_size(char *files_name, load_map_ *load_map);
char ***get_map(load_map_ *load_map);
void display_load_map(char ***map, game_ *game, int movement);
void display_layer_1(sfSprite ***map, game_ *game, int movement);
sfSprite ***my_malloc_map_sprite(int colum, int lines);
char ***my_malloc_map(int colum, int lines);
void init_map_square(char ***map, int y, int x);
void move_tiles(sfSprite ***map, game_ *, int y, int x);
void display_layer_2(sfSprite ***map, game_ *game, int movement);
char ***get_map_2(load_map_ *load_map);
void get_size_2(char *files_name, load_map_ *load_map);
int save_all(game_ *game, grid_cell_ *grid);
char ***my_malloc_big_tab(int colum, int lines);
int add_tileset(sfSprite ***map, sprite_ *sprite, char ***id_background);
void init_map(char ***map, load_map_ *load_map);
int add_tileset_2(sfSprite ***map, sprite_ *sprite, char ***id_background);
void move_rep(sfSprite *rep, int movement, game_ *game);
void get_size_3(char *files_name, load_map_ *load_map);
char ***get_map_3(load_map_ *load_map);
void save_hitbox(game_ *game, grid_cell_ *grid, FILE *file);
void its_background(game_ *game, grid_cell_ *grid, paint_ *paint);
void its_foreground(game_ *game, grid_cell_ *grid, paint_ *paint);
void its_hitbox(game_ *game, grid_cell_ *grid, paint_ *paint);
void display_foreground(game_ *game, grid_cell_ *grid, paint_ *paint);
void display_background(game_ *game, grid_cell_ *grid, paint_ *paint);
void display_hitbox(game_ *game, grid_cell_ *grid, paint_ *paint);
void display_mob(game_ *game, grid_cell_ *grid, paint_ *paint);
int display_layer(sfSprite ***map, game_ *game, int movement);
int wall_moov(game_ *game, grid_cell_ *wall_1, grid_cell_ *wall_2);
int moov_up_(grid_cell_ *grid);
int moov_down_(grid_cell_ *grid);
int moov_left_(grid_cell_ *grid);
int moov_right_(grid_cell_ *grid);
int display_layer_h(sfSprite ***map, game_ *game, sfVector2f pos);
void move_player(player_ *player);
void display_layer_hit(sfSprite ***map, game_ *game, int y,
sfVector2f pos);
void launch_layer(game_ *game, layer_ *layer, sfVector2f pos, sfSprite *rep);
void init_layer(layer_ *layer, load_map_ *load_map, gen_control_ *gen_control,
game_ *game);
void create_gen_mob(gen_control_ *gen_control, int i);
void create_first_sprite_mob(gen_control_ *gen_control, int i);
void its_mob(game_ *game, grid_cell_ *grid, paint_ *paint);
void open_close_hint(game_ *game);
void gen_control_disp(game_ *game);
void delete_foreground(game_ *game, grid_cell_ *grid);
void delete_background(game_ *game, grid_cell_ *grid);
void delete_hitbox(game_ *game, grid_cell_ *grid);
void delete_mob(game_ *game, grid_cell_ *grid);
void save_mob(game_ *game, grid_cell_ *grid, FILE *file);

#endif /* !MAP_GRID_H_ */
