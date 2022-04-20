/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void move_rep(sfSprite *rep, int movement)
{
    sfVector2f pos = sfSprite_getPosition(rep);

    if (movement == 0)
        pos.y -= 3;
    if (movement == 1)
        pos.x -= 3;
    if (movement == 2)
        pos.y += 3;
    if (movement == 3)
        pos.x += 3;
    sfSprite_setPosition(rep, pos);
}

void move_map(char ***map, int movement, int y, int x)
{
    sfVector2f pos =
    sfRectangleShape_getPosition((sfRectangleShape *)map[y][x]);

    if (movement == 0)
        pos.y -= 3;
    if (movement == 1)
        pos.x -= 3;
    if (movement == 2)
        pos.y += 3;
    if (movement == 3)
        pos.x += 3;
    sfRectangleShape_setPosition((sfRectangleShape *)map[y][x], pos);
}

void move_tiles(sfSprite ***map, int movement, int y, int x)
{
    sfVector2f pos = sfSprite_getPosition((sfSprite *)map[y][x]);

    if (movement == 0)
        pos.y -= 3;
    if (movement == 1)
        pos.x -= 3;
    if (movement == 2)
        pos.y += 3;
    if (movement == 3)
        pos.x += 3;
    sfSprite_setPosition(map[y][x], pos);
}
