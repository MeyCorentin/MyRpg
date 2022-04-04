/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create my settings menu
*/

#include "../../includes/rpg.h"

void create_button_set(game_ *game, menu_ *menu)
{
    menu->settings->button = malloc(sizeof(button_));
    menu->settings->button->sprite = sfSprite_create();
    menu->settings->button->texture = sfTexture_createFromFile
    ("pictures/menu/empty_box.png", NULL);
    menu->settings->button->position = (sfVector2f){1860, 10};
    menu->settings->button->scale = (sfVector2f){1, 1};
    sfSprite_setScale(menu->settings->button->sprite,
    menu->settings->button->scale);
    sfSprite_setTexture(menu->settings->button->sprite,
    menu->settings->button->texture, sfFalse);
    sfSprite_setPosition(menu->settings->button->sprite,
    menu->settings->button->position);
    menu->settings->button->rect = change_rect
    (menu->settings->button->rect, 50, 57);
    sfSprite_setTextureRect
    (menu->settings->button->sprite, menu->settings->button->rect);
}

void create_settings(game_ *game, menu_ *menu)
{
    menu->settings = malloc(sizeof(settings_));
    menu->settings->back = malloc(sizeof(button_));
    menu->settings->back->sprite = sfSprite_create();
    menu->settings->back->texture = sfTexture_createFromFile
    ("pictures/menu/menu.png", NULL);
    menu->settings->back->position = (sfVector2f){270, 150};
    sfSprite_setTexture(menu->settings->back->sprite,
    menu->settings->back->texture, sfFalse);
    sfSprite_setPosition(menu->settings->back->sprite,
    menu->settings->back->position);
    menu->settings->back->rect = change_rect
    (menu->settings->back->rect, 320, 180);
    sfSprite_setTextureRect(menu->settings->back->sprite,
    menu->settings->back->rect);
    menu->settings->back->scale = (sfVector2f){4, 4};
    sfSprite_setScale(menu->settings->back->sprite,
    menu->settings->back->scale);
    create_button_set(game, menu);
    create_texts(menu);
}
