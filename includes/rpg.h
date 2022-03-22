/*
** EPITECH PROJECT, 2021
** MY_RPG
** File description:
** It's the .h of my project my_rpg
*/

#ifndef PROJECT_H_
    #define PROJECT_H_

#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>

typedef struct game {
    sfRenderWindow *window;
    sfEvent event;
} game_;

int global_gestion(int argc, char **argv);
void launch_menu(char *pseudo);
void launch_game(game_ *game);

#endif /* PROJECT_H_ */
