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
    int click;
    int foreground_id;
    int background_id;
    int hitbox_id;
    int is_sprite;
    sfRectangleShape *rect;
    struct grid_cell *next_cell;
    struct grid_cell *prev_cell;
    struct sprite *foreground;
    struct sprite *background;
    struct sprite *hitbox;
} grid_cell_;

typedef struct paint {
    int scale;
} paint_;

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

typedef struct stats {
    int life;
    int attack;
    float speed;
} stats_;

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

typedef struct player {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    sfSprite *rep;
    int secs;
    int movement;
    int gold;
    int life;
    int m_up;
    int m_down;
    int m_left;
    int m_right;
    layer_ *layer;
    stats_ *stats;
} player_;

typedef struct sounds {
    sfMusic *ocean;
    sfMusic *summer_day;
    sfSound *click;
    sfSound *coin;
    sfSound *parrot;
    sfSound *item;
    sfSound *trash;
} sounds_;

typedef struct bonus {
    int all;
    int life;
    int attack;
    int gold;
    int speed;
} bonus_;

typedef struct chained_skill {
    struct chained_skill *first;
    struct chained_skill *prev;
    sfSprite *skill;
    sfVector2f pos_skill;
    sfVector2f pos_skill2;
    int type;
    int value;
    int active;
    struct chained_skill *next;
    int price;
    sfText *infos;
    sfText *cost;
    sfVector2f pos_infos;
    sfVector2f scale;
    sfVector2f pos_cost;
} chained_skill_;

typedef struct skill_tree {
    sfSprite *back;
    sfTexture *t_back;
    sfTexture *tree;
    chained_skill_ *first_skill;
    int x;
    int y;
} skill_tree_;

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

typedef struct life {
    button_ *hearth;
    struct life *next;
} life_;

typedef struct inventory {
    int page;
    char ***inv;
    button_ *back;
    button_ *back_quit;
    button_ *back_map;
    button_ *back_girl;
    button_ *back_stats;
    button_ *back_potion;
    button_ *back_craft;
    button_ *back_pad;
    int on_item;
    button_ *bar;
    button_ *select;
    text_ *gold;
    skill_tree_ *tree;
    life_ *life;
    int x_hearth;
} inventory_;

typedef struct clock {
    sfClock *clock;
    sfTime time;
    int secs;
    int ancien_sec;
    int hours;
    int days;
    int saison;
    int check_secs;
    button_ *infos;
    sfSprite *light;
    button_ *arrow;
    text_ *day;
    text_ *hour;
    sfColor color;
} clock_;

typedef struct boole {
    int on_button;
    int on_inv;
    int on_quit;
    int on_map;
    int on_girl;
    int on_stats;
    int on_craft;
    int on_potion;
    int on_pad;
    int on_tree;
} boole_;

typedef struct enemy {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f position;
    sfIntRect rect;
    sfClock *clock;
    int start;
    int max;
    sfTime time;
    int secs;
    struct enemy *next;
} enemy_;

typedef struct game {
    char *map;
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
    int layer;
    int speed;
    grid_cell_ *wall_1;
    grid_cell_ *wall_2;
    layer_ *layer_;
    sfSprite ***background;
    sfSprite ***foreground;
    sfSprite ***hitbox;
    bonus_ *bonus;
    boole_ *boole;
    text_ *who;
    enemy_ *first;
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
void create_ath(game_ *game);
void update_time(game_ *game);
void loop_tree(game_ *game);
chained_skill_ *get_last_skill(game_ *game, int cmpt, int level);
chained_skill_ *check_prev(game_ *game, int cmpt);
void draw_skill_tree(game_ *game, chained_skill_ *skill);
void create_tree(game_ *game);
void set_string_skills(game_ *game, chained_skill_ *skill);
chained_skill_ *create_skill(game_ *game, int cmpt, int level);
void active_bonus(game_ *game, chained_skill_ *skill);
void create_bonus(game_ *game);
void draw_hearth(game_ *game, life_ *hearth, int nb);
void create_life(game_ *game);
void add_hearth(life_ *hearth, int x, game_ *game);
void change_window(game_ *game);
void open_other_pages(game_ *game);
void clear_all(game_ *game);
void update_enemy(enemy_ *enemy, game_ *game);
void get_last_enemy(enemy_ *enemy, char *filepath, sfVector2f position,
sfIntRect rect);

#endif /* PROJECT_H_ */
