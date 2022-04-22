/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void event_pause(game_ *game)
{
    if (game->mouse.x > game->inv->quit->position.x && game->mouse.x <
    game->inv->quit->position.x + 370 && game->mouse.y > game->inv->quit->
    position.y && game->mouse.y < game->inv->quit->position.y + 140) {
        sfText_setColor(game->inv->text_quit->text, sfWhite);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            save_game(game);
            loop_menu(game, game->menu);
        }
    } else
        sfText_setColor(game->inv->text_quit->text, sfBlack);
    if (game->mouse.x > game->inv->settings->position.x && game->mouse.x <
    game->inv->settings->position.x + 370 && game->mouse.y > game->inv->
    settings->position.y && game->mouse.y < game->inv->settings->position.y +
    140) {
        sfText_setColor(game->inv->text_settings->text, sfWhite);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            launch_settings(game, game->menu);
    } else
        sfText_setColor(game->inv->text_settings->text, sfBlack);
}
