/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create my player
*/

#include "../../includes/rpg.h"

void move_player(player_ *player, game_ *game)
{
    if (game->boole->on_fight != 0) {
        if (sfKeyboard_isKeyPressed(sfKeyZ) && player->m_up == 1)
            player->movement = 2;
        if (sfKeyboard_isKeyPressed(sfKeyS) && player->m_down == 1)
            player->movement = 0;
        if (sfKeyboard_isKeyPressed(sfKeyQ) && player->m_left == 1)
            player->movement = 3;
        if (sfKeyboard_isKeyPressed(sfKeyD) && player->m_right == 1)
            player->movement = 1;
        sfSprite_setPosition(player->sprite, player->position);
    }
}

void update_player(game_ *game, player_ *player)
{
    player->movement = 4;
    player->time = sfClock_getElapsedTime(player->clock);
    player->secs = player->time.microseconds / 5000;
    move_player(player, game);
    if (player->secs > 30) {
        if (player->rect.left < 20 + 48)
            player->rect.left += 16;
        else
            player->rect.left = 22;
        player->rect.top = 15 + (32 * player->movement);
        sfSprite_setTextureRect(player->sprite, player->rect);
        sfClock_restart(player->clock);
    }
    sfRenderWindow_drawSprite(game->window, player->sprite, sfFalse);
}

void set_gold_player(game_ *game, char *pseudo)
{
    if (my_strcmp(pseudo, "Jessica") == 0)
        game->player->gold = 10000;
    else
        game->player->gold = 10;
    game->player->m_down = 1;
    game->player->m_up = 1;
    game->player->m_left = 1;
    game->player->m_right = 1;
}

void create_player(game_ *game, char *pseudo)
{
    game->player = malloc(sizeof(player_));
    game->player->sprite = sfSprite_create();
    game->player->texture = sfTexture_createFromFile
    ("pictures/player/elliot.png", NULL);
    game->player->scale = (sfVector2f){3, 3};
    game->player->position = (sfVector2f){950, 500};
    game->player->clock = sfClock_create();
    game->player->rect = change_rect(game->player->rect, 16, 32);
    game->player->rect.top = 15;
    game->player->rect.left = 22;
    sfSprite_setTexture(game->player->sprite, game->player->texture, sfFalse);
    sfSprite_setScale(game->player->sprite, game->player->scale);
    sfSprite_setPosition(game->player->sprite, game->player->position);
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    set_gold_player(game, pseudo);
    game->player->stats = malloc(sizeof(stats_));
    game->player->stats->life = 3;
    game->player->stats->attack = 1;
    game->player->stats->speed = 0;
}

void check_on_item(game_ *game, item_ *item, player_ *player)
{
    if (item->position.x >= player->position.x - 48 && item->position.y >=
    player->position.y + 48 && item->position.x <= player->position.x + 48 &&
    item->position.y <= player->position.y + 96 && item->on_inv == 1) {
        sfSound_play(game->sounds->item);
        add_item_to_inv(game, game->inv->inv, item);
    }
    if (item->next != NULL)
        check_on_item(game, item->next, player);
}
