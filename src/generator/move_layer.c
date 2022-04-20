/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void move_rep(sfSprite *rep, int movement, game_ *game)
{
    sfVector2f pos =
    sfSprite_getPosition(rep);

    if (movement == 0)
        pos.y -= 3 + game->player->stats->speed;
    if (movement == 1)
        pos.x -= 3 + game->player->stats->speed;
    if (movement == 2)
        pos.y += 3 + game->player->stats->speed;
    if (movement == 3)
        pos.x += 3 + game->player->stats->speed;
    sfSprite_setPosition(rep, pos);
}

void move_map(sfRectangleShape *map, int movement, game_ *game)
{
    sfVector2f pos = sfRectangleShape_getPosition(map);

    if (movement == 0)
        pos.y -= 3 + game->player->stats->speed;
    if (movement == 1)
        pos.x -= 3 + game->player->stats->speed;
    if (movement == 2)
        pos.y += 3 + game->player->stats->speed;
    if (movement == 3)
        pos.x += 3 + game->player->stats->speed;
    sfRectangleShape_setPosition(map, pos);
}

void move_background(sfSprite *map, int movement, game_ *game)
{
    sfVector2f pos = sfSprite_getPosition(map);

    if (movement == 0)
        pos.y -= 3 + game->player->stats->speed;
    if (movement == 1)
        pos.x -= 3 + game->player->stats->speed;
    if (movement == 2)
        pos.y += 3 + game->player->stats->speed;
    if (movement == 3)
        pos.x += 3 + game->player->stats->speed;
    sfSprite_setPosition(map, pos);
}
