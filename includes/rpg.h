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
#include <SFML/Audio.h>
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
    int save;
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
    button_ *bar_music;
    button_ *bar_sounds;
    button_ *music;
    button_ *sounds;
} settings_;

typedef struct saves {
    button_ *first;
    button_ *second;
    button_ *third;
} saves_;

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
    int on_load;
    saves_ *saves;
    text_ *score;
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
    char *back_full;
    char *fore_full;
    char *hit_full;
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

typedef struct layer {
    char ***map;
    char ***map_2;
    char ***map_3;
    sfSprite ***map_layer_1 ;
    sfSprite ***map_layer_2 ;
    sfSprite ***map_layer_3 ;
    char ***id_background ;
    char ***id_foreground ;
    char ***id_hitbox ;

} layer_;

typedef struct sounds {
    sfMusic *ocean;
    sfMusic *summer_day;
    sfSound *click;
    sfSound *coin;
    sfSound *parrot;
    sfSound *item;
    sfSound *trash;
} sounds_;

typedef struct item {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    int type;
    int stats;
    int on_inv;
    struct item *next;
    struct item *prev;
    int line;
    int col;
    int is_get;
} item_;

typedef struct inventory {
    int page;
    char ***inv;
    button_ *back;
    int on_item;
    button_ *bar;
    button_ *select;
} inventory_;

typedef struct clock {
    sfClock *clock;
    sfTime time;
    int secs;
} clock_;

typedef struct game {
    sfRenderWindow *window;
    sfEvent event;
    cursor_ *cursor;
    player_ *player;
    menu_ *menu;
    sounds_ *sounds;
    inventory_ *inv;
    clock_ *clock;
    item_ *first_item;
    sfVector2i mouse;
    int on_button;
    int  on_inv;
    int layer;
    int speed;
} game_;

void check_event_game(game_ *game);
int global_gestion(int argc, char **argv);
sfIntRect change_rect(sfIntRect rect, float x, float y);
void launch_game(game_ *game);
void create_player(game_ *game);
void update_player(game_ *game, player_ *player);
void create_inventory(game_ *game);
void update_inventory(game_ *game);
void draw_items(game_ *game, item_ *item, int movement, int status);
void add_items(game_ *game, item_ *item);
void add_item_to_inv(game_ *game, char ***inv, item_ *item);
void check_on_item(game_ *game, item_ *item, player_ *player);
void update_inv(game_ *game);
void check_event_items(game_ *game);
void inv_to_bar(item_ *item, game_ *game);
void move_select(game_ *game);
void open_close_inv(game_ *game);
void cancel_item(item_ *item, game_ *game);
void drop_item(item_ *item, game_ *game);
void delete_item(item_ *item, game_ *game);
void update_bar(game_ *game);

#endif /* PROJECT_H_ */
