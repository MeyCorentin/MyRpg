/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to move items on inventory
*/

#include "../../includes/rpg.h"

void cancel_item(item_ *item, game_ *game)
{
    sfSound_play(game->sounds->item);
    item->on_inv = 1;
    item->position.x = game->player->position.x + 16;
    item->position.y = game->player->position.y + 32 * game->player->scale.y;
    sfSprite_setPosition(item->sprite, item->position);
    game->inv->inv[item->line][item->col] = NULL;
}

void drop_item(item_ *item, game_ *game)
{
    sfSound_play(game->sounds->item);
    item->on_inv = 1;
    item->position.x = game->player->position.x + 16;
    item->position.y = game->player->position.y + 32 * game->player->scale.y
    + 10;
    sfSprite_setPosition(item->sprite, item->position);
    game->inv->inv[item->line][item->col] = NULL;
}

void delete_item(item_ *item, game_ *game)
{
    sfSound_play(game->sounds->trash);
    item->position.x = -32;
    sfSprite_setPosition(item->sprite, item->position);
    game->inv->inv[item->line][item->col] = NULL;
}
