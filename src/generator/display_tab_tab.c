/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void display_load_map(char ***map, game_ *game, int movement)
{
    int y = 0;
    int x = 0;

    for (y = 0; map[y]; y++) {
        for (x = 0; map[y][x]; x++) {
            move_map(map, movement, y, x);
            sfRenderWindow_drawRectangleShape(game->window,
            (sfRectangleShape *)map[y][x], sfFalse);
        }
    }
}

void display_layer_1(char ***map, game_ *game, int movement)
{
    sfVector2f pos;
    int y = 0;
    int x = 0;

    for (y = 0; map[y]; y++) {
        for (x = 0; map[y][x]; x++) {
            move_background(map, movement, y, x);
            sfRenderWindow_drawSprite(game->window,
            (sfSprite *)map[y][x], sfFalse);
        }
    }
}

void display_layer_2(char ***map, game_ *game, int movement, player_ *player)
{
    sfVector2f pos;
    sfVector2f pos_next;

    int y = 0;
    int x = 1;
    for (y = 0; map[y]; y++) {
        for (x = 1; map[y][x]; x++) {
            move_background(map, movement, y, x);
            sfRenderWindow_drawSprite(game->window,
            (sfSprite *)map[y][x], sfFalse);
        }
    }
}

void display_big_tab(char ***map)
{
    int y = 0;
    int x = 0;
    for (y = 0; map[y]; y++) {
        for (x = 0; map[y][x]; x++) {
            my_put_nbr(my_atoi(map[y][x]));
            my_putstr("|");
        }
        my_putstr("\n");
    }
}
