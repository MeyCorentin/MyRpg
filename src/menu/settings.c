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
