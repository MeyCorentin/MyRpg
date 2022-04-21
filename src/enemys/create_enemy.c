/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create an enemy
*/

#include "../../includes/rpg.h"

enemy_ *create_enemy(sfVector2f position, sfIntRect rect, int max)
{
    enemy_ *new = malloc(sizeof(enemy_));

    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile("pictures/enemys.png", NULL);
    new->scale = (sfVector2f){3, 3};
    new->position = position;
    new->rect = rect;
    new->clock = sfClock_create();
    new->secs = 0;
    new->next = NULL;
    new->max = max;
    new->start = rect.left;
    sfSprite_setTexture(new->sprite, new->texture, sfFalse);
    sfSprite_setScale(new->sprite, new->scale);
    sfSprite_setPosition(new->sprite, new->position);
    sfSprite_setTextureRect(new->sprite, new->rect);
    return (new);
}

void get_last_enemy(enemy_ *enemy, sfVector2f position,
sfIntRect rect, int max)
{
    if (enemy->next != NULL)
        get_last_enemy(enemy->next, position, rect, max);
    else if (!enemy)
        enemy = create_enemy(position, rect, max);
    else
        enemy->next = create_enemy(position, rect, max);
}

void update_enemy(enemy_ *enemy, game_ *game)
{
    enemy->time = sfClock_getElapsedTime(enemy->clock);
    enemy->secs = enemy->time.microseconds / 5000;
    if (enemy->secs > 30) {
        enemy->rect.left += enemy->rect.width;
        sfClock_restart(enemy->clock);
    }
    if (enemy->rect.left > enemy->max - enemy->rect.width)
        enemy->rect.left = enemy->start;
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    sfRenderWindow_drawSprite(game->window, enemy->sprite, sfFalse);
    if (enemy->next != NULL)
        update_enemy(enemy->next, game);
}
