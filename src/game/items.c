/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function to create items
*/

#include "../../includes/rpg.h"

void move_items(item_ *item, int value, int movement)
{
    if (movement == 0)
        item->position.y -= value;
    if (movement == 1)
        item->position.x -= value;
    if (movement == 2)
        item->position.y += value;
    if (movement == 3)
        item->position.x += value;
}

void draw_items(game_ *game, item_ *item, int movement, int status)
{
    if (item->on_inv == 1)
        move_items(item, 3, movement);
    sfSprite_setPosition(item->sprite, item->position);
    if ((status == 0 && item->on_inv == 0) || (status == 1 && item->on_inv
    == 1))
        sfRenderWindow_drawSprite(game->window, item->sprite, sfFalse);
    if (item->next != NULL)
        draw_items(game, item->next, movement, status);
}

void set_rect_item(item_ *item, int top, int left, item_ *prev)
{
    item->rect.left = left;
    item->rect.top = top;
    sfSprite_setTextureRect(item->sprite, item->rect);
    item->prev = prev;
}

item_ *create_item(int type, int stats, char *filename, sfVector2f position)
{
    item_ *item = malloc(sizeof(item_));

    item->sprite = sfSprite_create();
    item->texture = sfTexture_createFromFile(filename, NULL);
    item->stats = stats;
    item->type = type;
    item->position = position;
    item->scale = (sfVector2f){2, 2};
    item->rect = change_rect(item->rect, 16, 16);
    item->next = NULL;
    item->on_inv = 1;
    sfSprite_setTextureRect(item->sprite, item->rect);
    sfSprite_setTexture(item->sprite, item->texture, sfFalse);
    sfSprite_setScale(item->sprite, item->scale);
    sfSprite_setPosition(item->sprite, item->position);
    return (item);
}

void add_items(game_ *game, item_ *item)
{
    if (item == NULL) {
        game->first_item = create_item(1, 3, "pictures/items/weapons.png",
        (sfVector2f){200, 200});
        set_rect_item(game->first_item, 0, 0, NULL);
    } else if (item->next != NULL)
        add_items(game, item->next);
    else {
        item->next = create_item(1, 3, "pictures/items/weapons.png",
        (sfVector2f){400, 400});
        set_rect_item(item->next, 48, 96, NULL);
    }
}