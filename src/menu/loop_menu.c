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
    if (menu->on_parrot == 0)
        sfRenderWindow_drawSprite(game->window, menu->secret->sprite, sfFalse);
    sfRenderWindow_drawSprite(game->window, menu->parrot->sprite, sfFalse);
    sfRenderWindow_drawSprite(game->window, menu->new->sprite, sfFalse);
    sfRenderWindow_drawSprite(game->window, menu->exit->sprite, sfFalse);
    sfRenderWindow_drawSprite(game->window, menu->load->sprite, sfFalse);
    sfRenderWindow_drawSprite(game->window, menu->help->sprite, sfFalse);
    sfRenderWindow_drawSprite(game->window,
    menu->settings->button->sprite, sfFalse);
    update_animal(menu->parrot, 48, 48, game);
    update_cursor(game);
}

void check_event_menu(game_ *game, menu_ *menu)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)game->window);

    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyE))
            sfRenderWindow_close(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyN))
            launch_game(game);
        if (sfKeyboard_isKeyPressed(sfKeyL))
            launch_game(game);
        if (sfKeyboard_isKeyPressed(sfKeyG))
            launch_map_generator(game);
        check_button(game, menu->new, 1, menu);
        check_button(game, menu->load, 2, menu);
        check_button(game, menu->exit, 3, menu);
        check_parrot(game, menu, mouse);
        check_settings(game, menu, 0);
        event_cursor(game);
    }
}

void loop_menu(game_ *game, menu_ *menu)
{
    while (sfRenderWindow_isOpen(game->window)) {
        game->on_button = 1;
        sfRenderWindow_clear(game->window, sfBlue);
        check_event_menu(game, menu);
        draw_menu(game, menu);
        sfRenderWindow_display(game->window);
    }
}

void launch_menu(sfVideoMode mode, sfVector2u size)
{
    game_ *game = malloc(sizeof(game_));
    menu_ *menu = malloc(sizeof(menu_));

    game->menu = menu;
    game->window = sfRenderWindow_create(mode, "MY_RPG", \
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 120);
    sfRenderWindow_setSize(game->window, size);
    sfWindow_setMouseCursorVisible((sfWindow *)game->window, sfFalse);
    malloc_menu(menu);
    create_cursor(game);
    create_settings(game, menu);
    game->speed = 1;
    loop_menu(game, menu);
}
