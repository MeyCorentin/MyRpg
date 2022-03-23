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
} menu_;

void malloc_menu(menu_ *menu);
void launch_menu(char *pseudo);
void create_new(menu_ *menu);
void create_exit(menu_ *menu);
void create_load(menu_ *menu);
void create_parrot(menu_ *menu);
void update_animal(animal_ *animal, int x, int y);

#endif /* MENU_H_ */
