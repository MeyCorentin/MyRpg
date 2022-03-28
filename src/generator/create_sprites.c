/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function to create sprites buttons on generator
*/

#include "../../includes/rpg.h"

void set_sprite(sprite_ *sprite)
{
    sprite->next = malloc(sizeof(sprite_));
    sprite->next->sprite = sfSprite_create();
    sprite->next->position.x = sprite->position.x + sprite->rect.width *
    sprite->scale.x + 2;
    sprite->next->position.y = sprite->position.y;
    sprite->next->scale.x = 2;
    sprite->next->scale.y = 2;
    sprite->next->id = sprite->id + 1;
    sprite->next->next = NULL;
    sprite->next->first = sprite->first;
    sprite->next->rect = change_rect(sprite->next->rect, 16, 17);
    sprite->next->rect.top = sprite->rect.top;
    sprite->next->rect.left = sprite->rect.left + 16;
    sfSprite_setTexture(sprite->next->sprite,
    sprite->first->texture, sfFalse);
    sfSprite_setPosition(sprite->next->sprite,
    sprite->next->position);
    sfSprite_setScale(sprite->next->sprite, sprite->next->scale);
    sfSprite_setTextureRect(sprite->next->sprite,
    sprite->next->rect);
}

void create_sprites(sprite_ *sprite)
{
    set_sprite(sprite);
    if (sprite->next->rect.left > 695) {
        sprite->next->rect.left = 3;
        sprite->next->rect.top = sprite->rect.top + 17;
        sprite->next->position.x = 0;
        sprite->next->position.y = sprite->position.y + sprite->rect.height *
        sprite->scale.y + 2;
    }
    if ((sprite->next->rect.left < 695 || sprite->next->rect.left != 0) &&
    sprite->next->rect.top < 705)
        create_sprites(sprite->next);
}

void create_first_sprite(gen_control_ *gen_control)
{
    gen_control->list = malloc(sizeof(sprite_));
    gen_control->list->sprite = sfSprite_create();
    gen_control->list->texture = sfTexture_createFromFile
    ("pictures/env/spring.png", NULL);
    gen_control->list->position.x = 0;
    gen_control->list->position.y = 0;
    gen_control->list->scale.x = 2;
    gen_control->list->scale.y = 2;
    gen_control->list->next = NULL;
    gen_control->list->first = gen_control->list;
    gen_control->list->rect = change_rect(gen_control->list->rect, 16, 17);
    gen_control->list->rect.top = 0;
    gen_control->list->rect.left = 0;
    sfSprite_setTexture(gen_control->list->sprite,
    gen_control->list->texture, sfFalse);
    sfSprite_setPosition(gen_control->list->sprite,
    gen_control->list->position);
    sfSprite_setScale(gen_control->list->sprite, gen_control->list->scale);
    sfSprite_setTextureRect(gen_control->list->sprite,
    gen_control->list->rect);
}

void create_selected(gen_control_ *gen_control)
{
    gen_control->selected = malloc(sizeof(sprite_));
    gen_control->selected->sprite = sfSprite_create();
    gen_control->selected->texture = sfTexture_createFromFile
    ("pictures/env/spring.png", NULL);
    gen_control->selected->position.x = 1800;
    gen_control->selected->position.y = 450;
    gen_control->selected->scale.x = 4;
    gen_control->selected->scale.y = 4;
    gen_control->selected->next = NULL;
    gen_control->selected->first = gen_control->selected;
    gen_control->selected->rect = change_rect(gen_control->selected->rect,
    16, 17);
    gen_control->selected_ = 0;
    sfSprite_setTexture(gen_control->selected->sprite,
    gen_control->selected->texture, sfFalse);
    sfSprite_setPosition(gen_control->selected->sprite,
    gen_control->selected->position);
    sfSprite_setScale(gen_control->selected->sprite,
    gen_control->selected->scale);
    sfSprite_setTextureRect(gen_control->selected->sprite,
    gen_control->selected->rect);
}

void create_gen(gen_control_ *gen_control)
{
    gen_control->down = malloc(sizeof(button_));
    gen_control->up = malloc(sizeof(button_));
    gen_control->list = malloc(sizeof(sprite_));
    gen_control->zoom_down = malloc(sizeof(button_));
    gen_control->zoom_up = malloc(sizeof(button_));
    gen_control->selected = malloc(sizeof(sprite_));
    gen_control->sprites_on = 1;
    gen_control->list->id = 0;
    create_up(gen_control);
    create_down(gen_control);
    create_zoom_up(gen_control);
    create_zoom_down(gen_control);
    create_first_sprite(gen_control);
    create_sprites(gen_control->list);
    create_selected(gen_control);
}
