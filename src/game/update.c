/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void update_inv(game_ *game)
{
    update_inventory(game);
    if (game->on_inv == 0)
        draw_items(game, game->first_item, game->player->movement, 0);
    update_cursor(game);
}
