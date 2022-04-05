/*
** EPITECH PROJECT, 2021
** MY_RPG
** File description:
** It's the .h of my project my_rpg
*/

#include "my.h"
#include "map_grid.h"
#include "menu.h"
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>

#ifndef PROJECT_H_
    #define PROJECT_H_

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
    int on_button;
    int layer;
} game_;

void check_event_game(game_ *game);
int global_gestion(int argc, char **argv);
sfIntRect change_rect(sfIntRect rect, float x, float y);
void launch_game(game_ *game);
void create_player(game_ *game);
void update_player(game_ *game, player_ *player);

#endif /* PROJECT_H_ */
