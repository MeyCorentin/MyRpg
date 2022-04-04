/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void check_event_game(game_ *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        event_cursor(game);
    }
}

void launch_game(game_ *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        game->on_button = 1;
        sfRenderWindow_clear(game->window, sfWhite);
        check_event_game(game);
        update_cursor(game);
        sfRenderWindow_display(game->window);
    }
}
