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

typedef struct animal {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    sfVector2f move;
    sfClock *clock;
    sfTime time;
    int secs;
} animal_;

typedef struct load {
    sfSprite *load;
    sfTexture *t_load;
    sfVector2f pos_load;
    sfIntRect rect;
    int is_load;
} load_;

typedef struct button {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
} button_;

typedef struct menu {
    button_ *back;
    button_ *secret;
    load_ *load1;
    load_ *load2;
    load_ *load3;
    button_ *exit;
    button_ *new;
    button_ *load;
    button_ *logo;
    button_ *params;
    button_ *sounds;
    button_ *help;
    animal_ *parrot;
    int on_parrot;
} menu_;

typedef struct sprite {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    struct sprite *next;
    struct sprite *first;
} sprite_;

typedef struct gen_control {
    button_ *up;
    button_ *down;
    button_ *zoom_up;
    button_ *zoom_down;
    sprite_ *list;
    sprite_ *selected;
} gen_control_;

void malloc_menu(menu_ *menu);
void launch_menu(char *pseudo);
void create_new(menu_ *menu);
void create_exit(menu_ *menu);
void create_load(menu_ *menu);
void create_parrot(menu_ *menu);
void update_animal(animal_ *animal, int x, int y);
void check_button(game_ *game, button_ *button, int who);
void create_secret(menu_ *menu);
void check_parrot(game_ *game, menu_ *menu);
void create_help(menu_ *menu);
void check_square(game_ *game, button_ *button, int who);
void create_up(gen_control_ *gen_control);
void create_down(gen_control_ *gen_control);
void create_sprites(sprite_ *sprite);
void create_zoom_down(gen_control_ *gen_control);
void create_zoom_up(gen_control_ *gen_control);
void create_selected(gen_control_ *gen_control);
void create_first_sprite(gen_control_ *gen_control);
void draw_env(game_ *game, sprite_ *sprite);
void interact_sprite(game_ *game, sprite_ *sprite, gen_control_ *gen_control);
void draw_sprites_gen(game_ *game, gen_control_ *gen_control);
void create_gen(gen_control_ *gen_control);

#endif /* MENU_H_ */
