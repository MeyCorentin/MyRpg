/*
** EPITECH PROJECT, 2021
** MY_RPG
** File description:
** It's the .h of my project my_rpg
*/

#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>

#ifndef MENU_H_
    #define MENU_H_

    #include "rpg.h"
    #include "map_grid.h"

void malloc_menu(menu_ *menu);
void launch_menu(sfVideoMode mode, sfVector2u size);
void create_new(menu_ *menu);
void create_exit(menu_ *menu);
void create_load(menu_ *menu);
void create_parrot(menu_ *menu);
void update_animal(animal_ *animal, int x, int y, game_ *game);
void check_button(game_ *game, button_ *button, int who, menu_ *menu);
void create_secret(menu_ *menu);
void check_parrot(game_ *game, menu_ *menu, sfVector2i mouse);
void create_help(menu_ *menu);
void check_square(game_ *game, button_ *button, int who, menu_ *menu);
void create_up(gen_control_ *gen_control);
void create_down(gen_control_ *gen_control);
void create_sprites(sprite_ *sprite, int i);
void create_zoom_down(gen_control_ *gen_control);
void create_zoom_up(gen_control_ *gen_control);
void create_selected(gen_control_ *gen_control);
void create_first_sprite(gen_control_ *gen_control, int i);
void draw_env(game_ *game, sprite_ *sprite);
void interact_sprite(game_ *game, sprite_ *sprite, gen_control_ *gen_control);
void draw_sprites_gen(game_ *game, gen_control_ *gen_control);
void create_gen(gen_control_ *gen_control, int i);
void create_cursor(game_ *game);
void update_cursor(game_ *game);
void event_cursor(game_ *game);
void create_settings(game_ *game, menu_ *menu);
void launch_settings(game_ *game, menu_ *menu);
void check_settings(game_ *game, menu_ *menu, int what);
void create_texts(menu_ *menu);
char *my_strcat(char *dest, char const *src);
void loop_menu(game_ *game, menu_ *menu);

#endif /* MENU_H_ */
