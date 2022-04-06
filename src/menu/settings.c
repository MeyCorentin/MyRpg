/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create my settings menu
*/

#include "../../includes/rpg.h"

void event_settings(game_ *game, menu_ *menu)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            menu->settings->in_settings = 1;
        check_settings(game, menu, 1);
        event_buttons(game, menu);
        event_cursor(game);
    }
}

void check_settings(game_ *game, menu_ *menu, int what)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)game->window);

    if (mouse.x > menu->settings->button->position.x && mouse.x <
    menu->settings->button->position.x + menu->settings->button->rect.width *
    menu->settings->button->scale.x && mouse.y > menu->settings->button->
    position.y && mouse.y < menu->settings->button->position.y + menu->
    settings->button->rect.height * menu->settings->button->scale.y) {
        game->on_button = 0;
        menu->settings->button->rect.left = 50;
        if (game->event.type == sfEvtMouseButtonReleased && what == 0)
            launch_settings(game, menu);
        if (game->event.type == sfEvtMouseButtonReleased && what == 1)
            menu->settings->in_settings = 1;
    } else
        menu->settings->button->rect.left = 0;
    sfSprite_setTextureRect(menu->settings->button->sprite,
    menu->settings->button->rect);
}

void launch_settings(game_ *game, menu_ *menu)
{
    menu->settings->in_settings = 0;
    while (sfRenderWindow_isOpen(game->window) && menu->settings->in_settings
    == 0) {
        game->on_button = 1;
        sfRenderWindow_clear(game->window, sfBlack);
        event_settings(game, menu);
        draw_settings(game, menu);
        sfRenderWindow_display(game->window);
    }
}
