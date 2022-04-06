/*
** EPITECH PROJECT, 2021
** MY_RPG
** File description:
** It's the .h of my project my_rpg
*/

#include "my.h"
#include "map_grid.h"
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include "menu.h"

#ifndef PROJECT_H_
    #define PROJECT_H_

typedef struct animal {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *r_texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    int secs;
    int moved;
    int version;
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

typedef struct text {
    sfText *text;
    sfVector2f position;
    sfVector2f scale;
    sfFont *font;
    char *string;
} text_;

typedef struct settings {
    button_ *back;
    button_ *button;
    int in_settings;
    text_ *all;
    text_ *max;
    text_ *mid;
    text_ *min;
    text_ *big;
    text_ *little;
} settings_;

typedef struct menu {
    settings_ *settings;
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
    animal_ *coin;
    int on_parrot;
} menu_;

typedef struct sprite {
    int ok;
    int page;
    int id;
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
    int sprites_on;
    int selected_;
} gen_control_;

typedef struct cursor {
    sfSprite *sprite;
    sfTexture *basic;
    sfTexture *clicked;
    sfVector2f position;
} cursor_;

typedef struct load_map {
    char *full_file;
    int y_size;
    int x_size;
} load_map_;

typedef struct player {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    int secs;
    int movement;
} player_;

typedef struct game {
    sfRenderWindow *window;
    sfEvent event;
    cursor_ *cursor;
    player_ *player;
    menu_ *menu;
    int on_button;
    int layer;
    int speed;
} game_;

void check_event_game(game_ *game);
int global_gestion(int argc, char **argv);
sfIntRect change_rect(sfIntRect rect, float x, float y);
void launch_game(game_ *game);
void create_player(game_ *game);
void update_player(game_ *game, player_ *player);

#endif /* PROJECT_H_ */
