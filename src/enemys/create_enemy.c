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
    new->texture = sfTexture_createFromFile("pictures/env/all_mob.png", NULL);
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
    if (enemy->next != NULL) {
        get_last_enemy(enemy->next, position, rect, max);
    } else {
        enemy->next = create_enemy(position, rect, max);
    }
}

void init_map_mob(int y, int x, layer_ *layer, game_ *game)
{
    sfVector2f pos = {40 * x, 40 * y};

    if (my_atoi(layer->id_mob[y][x]) == 1)
        get_last_enemy(game->first, pos, (sfIntRect){22, 50, 16, 16}, 100);
    if (my_atoi(layer->id_mob[y][x]) == 2)
        get_last_enemy(game->first, pos, (sfIntRect){22, 145, 16, 16}, 100);
    if (my_atoi(layer->id_mob[y][x]) == 3)
        get_last_enemy(game->first, pos, (sfIntRect){22, 334, 16, 32}, 100);
    if (my_atoi(layer->id_mob[y][x]) == 4)
        get_last_enemy(game->first, pos, (sfIntRect){22, 480, 16, 32}, 100);
    if (my_atoi(layer->id_mob[y][x]) == 5)
        get_last_enemy(game->first, pos, (sfIntRect){27, 695, 16, 16}, 105);
    if (my_atoi(layer->id_mob[y][x]) == 6)
        get_last_enemy(game->first, pos, (sfIntRect){27, 775, 16, 16}, 105);
    if (my_atoi(layer->id_mob[y][x]) == 7)
        get_last_enemy(game->first, pos, (sfIntRect){22, 871, 16, 32}, 100);
}

void move_enemy(enemy_ *enemy, int movement, game_ *game)
{
    if (movement == 0)
        enemy->position.y -= 3 + game->player->stats->speed;
    if (movement == 1)
        enemy->position.x -= 3 + game->player->stats->speed;
    if (movement == 2)
        enemy->position.y += 3 + game->player->stats->speed;
    if (movement == 3)
        enemy->position.x += 3 + game->player->stats->speed;
    sfSprite_setPosition(enemy->sprite, enemy->position);
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
    move_enemy(enemy, game->player->movement, game);
    sfRenderWindow_drawSprite(game->window, enemy->sprite, sfFalse);
    if (enemy->next != NULL)
        update_enemy(enemy->next, game);
}
