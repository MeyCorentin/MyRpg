/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions create the time gestion
*/

#include "../../includes/rpg.h"

void update_time(game_ *game)
{
    game->clock->time = sfClock_getElapsedTime(game->clock->clock);
    game->clock->secs = game->clock->time.microseconds / 100000;
    sfRenderWindow_drawSprite(game->window, game->clock->infos->sprite,
    sfFalse);
    if (game->clock->secs > 450 && game->clock->secs < 600 && game->clock->color.a < 100) {
        sfSprite_setPosition(game->clock->arrow->sprite, (sfVector2f){1712, 55});
        sfSprite_setRotation(game->clock->arrow->sprite, 295);
        game->clock->color.a += 1;
    }
    if (game->clock->secs > 600 && game->clock->secs < 900) {
        sfSprite_setRotation(game->clock->arrow->sprite, 350);
        sfSprite_setPosition(game->clock->arrow->sprite, (sfVector2f){1750, 20});
    }
    if (game->clock->secs > 1050 || game->clock->secs < 450) {
        sfSprite_setRotation(game->clock->arrow->sprite, 245);
        sfSprite_setPosition(game->clock->arrow->sprite, (sfVector2f){1724, 102});
    }
    if (game->clock->secs > 900 && game->clock->secs < 1050 && game->clock->color.a > 0) {
        sfSprite_setRotation(game->clock->arrow->sprite, 190);
        sfSprite_setPosition(game->clock->arrow->sprite, (sfVector2f){1770, 120});
        game->clock->color.a -= 1;
    }
    sfSprite_setColor(game->clock->light, game->clock->color);
    if (game->clock->secs > 1200) {
        sfClock_restart(game->clock->clock);
        game->clock->days += 1;
    }
    sfRenderWindow_drawSprite(game->window, game->clock->arrow->sprite,
    sfFalse);
    sfText_setString(game->inv->gold->text, new_put_nbr(game->player->gold));
    sfRenderWindow_drawText(game->window, game->inv->gold->text, sfFalse);
}

button_ *create_sprite(sfVector2f pos, sfVector2f scale, sfIntRect rect,
char *filepath)
{
    button_ *sprite = malloc(sizeof(button_));

    sprite->texture = sfTexture_createFromFile(filepath, NULL);
    sprite->sprite = sfSprite_create();
    sprite->position = pos;
    sprite->scale = scale;
    sprite->rect = rect;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setPosition(sprite->sprite, sprite->position);
    sfSprite_setScale(sprite->sprite, sprite->scale);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return (sprite);
}

void create_light(clock_ *clock)
{
    sfTexture *texture = sfTexture_createFromFile("pictures/ath/white.png",
    NULL);

    clock->color = (sfColor){0, 0, 255, 0};
    clock->light = sfSprite_create();
    sfSprite_setTexture(clock->light, texture, sfFalse);
    sfSprite_setScale(clock->light, (sfVector2f){10, 10});
    sfSprite_setColor(clock->light, clock->color);
    sfSprite_setPosition(clock->light, (sfVector2f){0, 0});
}

void create_ath(game_ *game)
{
    game->clock->infos = create_sprite((sfVector2f){1700, 10},
    (sfVector2f){3, 3}, (sfIntRect){0, 0, 72, 59}, "pictures/ath/clock.png");
    create_light(game->clock);
    game->clock->arrow = create_sprite((sfVector2f){1750, 15},
    (sfVector2f){3, 3}, (sfIntRect){72, 0, 8, 20}, "pictures/ath/clock.png");
    create_light(game->clock);
    game->inv->gold = create_text(new_put_nbr(game->player->gold),
    (sfVector2f){1, 1}, (sfVector2f){1755, 145}, "font/Stardew_Valley.ttf");
    game->clock->days = 0;
    game->clock->saison = 0;
}
