/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** fight_enemy
*/

#include "../../includes/rpg.h"

enemy_ *init_fight_mob(int k)
{
    enemy_ *temp = malloc(sizeof(enemy_));
    sfVector2f pos = {1150, 350};
    switch (k) {
        case (1): temp = create_enemy(pos, (sfIntRect){22, 50, 16, 16}, 100);
            return (temp);
        case (2): temp = create_enemy(pos, (sfIntRect){22, 145, 16, 16}, 100);
            return (temp);
        case (3): temp = create_enemy(pos, (sfIntRect){22, 334, 16, 32}, 100);
            return (temp);
        case (4): temp = create_enemy(pos, (sfIntRect){22, 480, 16, 32}, 100);
            return (temp);
        case (5): temp = create_enemy(pos, (sfIntRect){27, 695, 16, 16}, 105);
            return (temp);
        case (6): temp = create_enemy(pos, (sfIntRect){27, 775, 16, 16}, 105);
            return (temp);
        case (7): temp = create_enemy(pos, (sfIntRect){22, 871, 16, 32}, 100);
            return (temp);
        default:
            return (temp);
    }
}

void update_enemy_f(enemy_ *enemy, game_ *game)
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
    sfSprite_setScale(enemy->sprite, (sfVector2f){7, 7});
    move_enemy(enemy, game->player->movement, game);
    sfRenderWindow_drawSprite(game->window, enemy->sprite, sfFalse);
    if (enemy->next != NULL)
        update_enemy_f(enemy->next, game);
}
