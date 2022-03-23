/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function to create my menu
*/

#include "../../includes/rpg.h"

void create_new(menu_ *menu)
{
    menu->new->sprite = sfSprite_create();
    menu->new->texture = sfTexture_createFromFile\
    ("pictures/menu/buttons.png", NULL);
    menu->new->position.x = 440;
    menu->new->position.y = 800;
    menu->new->scale.x = 3;
    menu->new->scale.y = 3;
    sfSprite_setTexture(menu->new->sprite, menu->new->texture, sfFalse);
    sfSprite_setPosition(menu->new->sprite, menu->new->position);
    sfSprite_setScale(menu->new->sprite, menu->new->scale);
    menu->new->rect = change_rect(menu->new->rect, 74, 58);
    menu->new->rect.top = 187;
    sfSprite_setTextureRect(menu->new->sprite, menu->new->rect);
}

void create_exit(menu_ *menu)
{
    menu->exit->sprite = sfSprite_create();
    menu->exit->texture = sfTexture_createFromFile\
    ("pictures/menu/buttons.png", NULL);
    menu->exit->position.x = menu->new->position.x + 800;
    menu->exit->position.y = 800;
    menu->exit->scale.x = 3;
    menu->exit->scale.y = 3;
    sfSprite_setTexture(menu->exit->sprite, menu->exit->texture, sfFalse);
    sfSprite_setPosition(menu->exit->sprite, menu->exit->position);
    sfSprite_setScale(menu->exit->sprite, menu->exit->scale);
    menu->exit->rect = change_rect(menu->exit->rect, 74, 58);
    menu->exit->rect.top = 187;
    menu->exit->rect.left = 222;
    sfSprite_setTextureRect(menu->exit->sprite, menu->exit->rect);
}

void create_load(menu_ *menu)
{
    menu->load->sprite = sfSprite_create();
    menu->load->texture = sfTexture_createFromFile\
    ("pictures/menu/buttons.png", NULL);
    menu->load->position.x = menu->new->position.x + 400;
    menu->load->position.y = 800;
    menu->load->scale.x = 3;
    menu->load->scale.y = 3;
    sfSprite_setTexture(menu->load->sprite, menu->load->texture, sfFalse);
    sfSprite_setPosition(menu->load->sprite, menu->load->position);
    sfSprite_setScale(menu->load->sprite, menu->load->scale);
    menu->load->rect = change_rect(menu->load->rect, 74, 58);
    menu->load->rect.top = 187;
    menu->load->rect.left = 74;
    sfSprite_setTextureRect(menu->load->sprite, menu->load->rect);
}
