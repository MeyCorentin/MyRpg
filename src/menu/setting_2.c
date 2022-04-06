/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create my settings menu
*/

#include "../../includes/rpg.h"

void draw_settings(game_ *game, menu_ *menu)
{
    sfRenderWindow_drawSprite(game->window,
    menu->settings->back->sprite, sfFalse);
    sfRenderWindow_drawSprite(game->window,
    menu->settings->button->sprite, sfFalse);
    sfRenderWindow_drawText(game->window, menu->settings->all->text, sfFalse);
    sfRenderWindow_drawText(game->window, menu->settings->all->text, sfFalse);
    sfRenderWindow_drawText(game->window, menu->settings->big->text, sfFalse);
    sfRenderWindow_drawText(game->window, menu->settings->little->text,
    sfFalse);
    sfRenderWindow_drawText(game->window, menu->settings->max->text, sfFalse);
    sfRenderWindow_drawText(game->window, menu->settings->min->text, sfFalse);
    sfRenderWindow_drawText(game->window, menu->settings->mid->text, sfFalse);
    update_cursor(game);
}

void do_settings(game_ *game, int action)
{
    if (action == 0) {
        sfRenderWindow_setFramerateLimit(game->window, 120);
        game->speed = 1;
    }
    if (action == 1) {
        sfRenderWindow_setFramerateLimit(game->window, 60);
        game->speed = 2;
    }
    if (action == 2) {
        sfRenderWindow_setFramerateLimit(game->window, 30);
        game->speed = 4;
    }
    if (action == 3) {
        sfRenderWindow_close(game->window);
        launch_menu((sfVideoMode){1920, 1080, 120}, (sfVector2u){1920, 1080});
    }
    if (action == 4) {
        sfRenderWindow_close(game->window);
        launch_menu((sfVideoMode){800, 600, 120}, (sfVector2u){800, 600});
    }
}

void is_on_button(game_ *game, text_ *text, int len, int action)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)game->window);

    if (mouse.x > text->position.x && mouse.x < text->position.x + len &&
    mouse.y > text->position.y && mouse.y < text->position.y + 60) {
        sfText_setColor(text->text, sfRed);
        if (game->event.type == sfEvtMouseButtonReleased)
            do_settings(game, action);
    } else
        sfText_setColor(text->text, sfBlack);
}

void event_buttons(game_ *game, menu_ *menu)
{
    is_on_button(game, menu->settings->max, 155, 0);
    is_on_button(game, menu->settings->mid, 135, 1);
    is_on_button(game, menu->settings->min, 130, 2);
    is_on_button(game, menu->settings->big, 230, 3);
    is_on_button(game, menu->settings->little, 190, 4);
}