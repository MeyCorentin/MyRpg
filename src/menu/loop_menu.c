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
    if (menu->on_load == 1) {
        sfRenderWindow_drawSprite(game->window, menu->logo->sprite, sfFalse);
        sfRenderWindow_drawSprite(game->window, menu->new->sprite, sfFalse);
        sfRenderWindow_drawSprite(game->window, menu->exit->sprite, sfFalse);
        sfRenderWindow_drawSprite(game->window, menu->load->sprite, sfFalse);
    } else {
        sfRenderWindow_drawSprite(game->window, menu->saves->first->sprite,
        sfFalse);
        sfRenderWindow_drawSprite(game->window, menu->saves->second->sprite,
        sfFalse);
        sfRenderWindow_drawSprite(game->window, menu->saves->third->sprite,
        sfFalse);
    }
    update_coin(menu->coin, game);
    update_animal(menu->parrot, 48, 48, game);
    sfRenderWindow_drawSprite(game->window, menu->help->sprite, sfFalse);
    sfRenderWindow_drawSprite(game->window,
    menu->settings->button->sprite, sfFalse);
    update_cursor(game);
}

void check_all_buttons(game_ *game, menu_ *menu)
{
    check_button(game, menu->new, 1, menu);
    check_button(game, menu->load, 2, menu);
    check_button(game, menu->exit, 3, menu);
    check_saves(game, menu->saves->first, 4, menu);
    check_saves(game, menu->saves->second, 5, menu);
    check_saves(game, menu->saves->third, 6, menu);
}

void check_event_menu(game_ *game, menu_ *menu)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        game->mouse = sfMouse_getPositionRenderWindow(game->window);
        if (game->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyE))
            sfRenderWindow_close(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyN))
            launch_game(game);
        if (sfKeyboard_isKeyPressed(sfKeyL))
            menu->on_load = 0;
        if (sfKeyboard_isKeyPressed(sfKeyG))
            launch_map_generator(game);
        if (menu->on_load == 0 && sfKeyboard_isKeyPressed(sfKeyEscape))
            menu->on_load = 1;
        check_all_buttons(game, menu);
        check_parrot(game, menu, game->mouse);
        check_on_coin(game, menu->coin, menu->parrot);
        check_settings(game, menu, 0);
        check_help(game, menu, 0);
        event_cursor(game);
    }
}

void loop_menu(game_ *game, menu_ *menu)
{
    sfMusic_play(game->sounds->ocean);
    while (sfRenderWindow_isOpen(game->window)) {
        game->mouse = sfMouse_getPositionRenderWindow(game->window);
        menu->back->rect.top = 0;
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
    create_audios(game);
    game->speed = 1;
    menu->on_load = 1;
    loop_menu(game, menu);
}
