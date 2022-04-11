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

void move_select(game_ *game)
{
    if (game->event.type == sfEvtMouseWheelScrolled) {
        game->inv->select->position.x += 48;
        if (game->inv->select->position.x >= 690 + 576)
            game->inv->select->position.x = 690;
        sfSprite_setPosition(game->inv->select->sprite,
        game->inv->select->position);
    }
}

void update_bar(game_ *game)
{
    if (game->on_inv == 1) {
        sfRenderWindow_drawSprite
        (game->window, game->inv->bar->sprite, sfFalse);
        draw_items(game, game->first_item, game->player->movement, 1);
        sfRenderWindow_drawSprite(game->window, game->inv->select->sprite,
        sfFalse);
    }
}

void open_close_inv(game_ *game)
{
    if (game->on_inv == 1 && sfKeyboard_isKeyPressed(sfKeyI) &&
    game->clock->secs != 0) {
        game->clock->secs = 0;
        game->on_inv = 0;
        inv_to_bar(game->first_item, game);
    }
    if (game->on_inv == 0 && sfKeyboard_isKeyPressed(sfKeyI) &&
    game->clock->secs != 0) {
        game->clock->secs = 0;
        game->on_inv = 1;
        inv_to_bar(game->first_item, game);
    }
}
