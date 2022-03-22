/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my menu
*/

#include "../../includes/rpg.h"

void check_event_menu(game_ *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyQ))
            sfRenderWindow_close(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyN))
            launch_game(game);
        if (sfKeyboard_isKeyPressed(sfKeyL))
            launch_game(game);
    }
}

void launch_menu(char *pseudo)
{
    sfVideoMode mode = {1920, 1080, 120};
    game_ *game = malloc(sizeof(game_));

    game->window = sfRenderWindow_create(mode, "MY_RPG", \
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 240);
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlue);
        check_event_menu(game);
        sfRenderWindow_display(game->window);
    }
}
