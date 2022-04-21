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
    update_bestiary(game);
    if (game->boole->on_inv == 0)
        draw_items(game, game->first_item, game->player->movement, 0);
    if (game->boole->on_tree == 0)
        loop_tree(game);
    update_time(game);
    draw_hearth(game, game->inv->life, game->player->stats->life);
    update_cursor(game);
}

void update_bar(game_ *game)
{
    if (game->boole->on_inv == 1) {
        sfRenderWindow_drawSprite
        (game->window, game->inv->bar->sprite, sfFalse);
        draw_items(game, game->first_item, game->player->movement, 1);
        sfRenderWindow_drawSprite(game->window, game->inv->select->sprite,
        sfFalse);
    }
}

void open_close_inv(game_ *game)
{
    if (game->boole->on_inv == 1 && sfKeyboard_isKeyPressed(sfKeyI) &&
    game->clock->check_secs != 0) {
        game->clock->check_secs = 0;
        game->boole->on_best = 1;
        game->boole->on_inv = 0;
        inv_to_bar(game->first_item, game);
    } if (game->boole->on_inv == 0 && game->clock->check_secs != 0 &&
    (sfKeyboard_isKeyPressed(sfKeyI) || sfKeyboard_isKeyPressed(sfKeyEscape) ||
    (game->mouse.x > 1285 && game->mouse.x < 1318 && game->mouse.y > 200 &&
    game->mouse.y < 233 && sfMouse_isButtonPressed(sfMouseLeft))) &&
    game->clock->check_secs != 0) {
        game->clock->check_secs = 0;
        game->boole->on_inv = 1;
        inv_to_bar(game->first_item, game);
    } if (game->boole->on_tree == 1 && game->mouse.x > 1310 && game->mouse.x <
    1350 && game->mouse.y > 280 &&
    game->mouse.y < 313 && sfMouse_isButtonPressed(sfMouseLeft)) {
        game->clock->check_secs = 0;
        game->boole->on_tree = 0;
    }
}
