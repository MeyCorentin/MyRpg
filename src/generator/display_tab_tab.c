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
            sfRenderWindow_drawRectangleShape(game->window,
            (sfRectangleShape *)map[y][x], sfFalse);
        }
    }
}

void display_layer_(sfSprite ***map, game_ *game, int movement, int y)
{
    int x = 0;

    for (x = 0; map[y][x]; x++) {
        if (map[y][x] != NULL) {
            sfRenderWindow_drawSprite(game->window, map[y][x], sfFalse);
        }
    }
}

int display_layer_h(sfSprite ***map, game_ *game, sfVector2f pos)
{
    int y = 0;
    if (game->player->m_left != 0)
        game->player->m_left = 1;
    if (game->player->m_right != 0)
        game->player->m_right = 1;
    if (game->player->m_down != 0)
        game->player->m_down = 1;
    if (game->player->m_up != 0)
        game->player->m_up = 1;

    for (y = 0; map[y]; y++) {
        display_layer_hit(map, game, y, pos);
    }
    return (0);
}

int display_layer(sfSprite ***map, game_ *game, int movement)
{
    int y = 0;

    for (y = 0; map[y]; y++) {
        display_layer_(map, game, movement, y);
    }
    return (0);
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
