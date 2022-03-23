/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function to create my menu
*/

#include "../../includes/rpg.h"

void create_parrot(menu_ *menu)
{
    menu->parrot->sprite = sfSprite_create();
    menu->parrot->texture = sfTexture_createFromFile\
    ("pictures/menu/parrot.png", NULL);
    menu->parrot->position.x = 1920;
    menu->parrot->position.y = 10;
    menu->parrot->scale.x = 3;
    menu->parrot->scale.y = 3;
    sfSprite_setTexture(menu->parrot->sprite, menu->parrot->texture, sfFalse);
    sfSprite_setPosition(menu->parrot->sprite, menu->parrot->position);
    sfSprite_setScale(menu->parrot->sprite, menu->parrot->scale);
    menu->parrot->rect = change_rect(menu->parrot->rect, 24, 24);
    menu->parrot->rect.top = 48;
    menu->parrot->rect.left = 48;
    sfSprite_setTextureRect(menu->parrot->sprite, menu->parrot->rect);
    menu->parrot->clock = sfClock_create();
    menu->parrot->move.x = -1;
    menu->parrot->move.y = 0;
}
