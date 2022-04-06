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

void display_layer_1(char ***map, game_ *game)
{
    sfVector2f pos;
    int y = 0;
    int x = 0;
    for (y = 0; map[y]; y++) {
        for (x = 0; map[y][x]; x++) {
            pos.x = 40 * x;
            pos.y = 40 * y;
            sfSprite_setPosition(map[y][x], pos);
            sfRenderWindow_drawSprite(game->window, map[y][x], sfFalse);
        }
    }
}
