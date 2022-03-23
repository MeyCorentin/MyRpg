/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my menu
*/

#include "../../includes/rpg.h"

void draw_menu(game_ *game, menu_ *menu)
{
    sfRenderWindow_drawSprite(game->window, menu->back->sprite, sfFalse);
    sfRenderWindow_drawSprite(game->window, menu->logo->sprite, sfFalse);
    sfRenderWindow_drawSprite(game->window, menu->new->sprite, sfFalse);
    sfRenderWindow_drawSprite(game->window, menu->exit->sprite, sfFalse);
    sfRenderWindow_drawSprite(game->window, menu->load->sprite, sfFalse);
    sfRenderWindow_drawSprite(game->window, menu->parrot->sprite, sfFalse);
    update_animal(menu->parrot, 48, 48);
}

void check_event_menu(game_ *game, menu_ *menu)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyE))
            sfRenderWindow_close(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyN))
            launch_game(game);
        if (sfKeyboard_isKeyPressed(sfKeyL))
            launch_game(game);
        if (sfKeyboard_isKeyPressed(sfKeyG))
            launch_map_generator(game);
    }
}

void launch_menu(char *pseudo)
{
    sfVideoMode mode = {1920, 1080, 120};
    game_ *game = malloc(sizeof(game_));
    menu_ *menu = malloc(sizeof(menu_));

    game->window = sfRenderWindow_create(mode, "MY_RPG", \
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 240);
    malloc_menu(menu);
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlue);
        check_event_menu(game, menu);
        draw_menu(game, menu);
        sfRenderWindow_display(game->window);
    }
}
