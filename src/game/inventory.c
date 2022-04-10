/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

int set_pos_item(game_ *game, char ***inv, item_ *item, int line)
{
    for (int col = 0; col != 12; col += 1) {
        if (!inv[line][col]) {
            inv[line][col] = (char *)item;
            item->position.x = game->inv->back->position.x
            + 38 + (48 * col);
            item->position.y = game->inv->back->position.y
            + 103 + (40 * line);
            return (0);
        }
    }
    return (1);
}

void add_item_to_inv(game_ *game, char ***inv, item_ *item)
{
    int line = 0;

    item->on_inv = 0;
    for (; line != 3; line += 1) {
        if (set_pos_item(game, inv, item, line) == 0)
            return;
    }
}

char ***malloc_inv(void)
{
    char ***temp = malloc(sizeof(char *) * (4));
    int line = 0;
    int col = 0;

    for (; line != 3; line += 1) {
        temp[line] = malloc(sizeof(char *) * 13);
        for (col = 0; col != 12; col += 1) {
            temp[line][col] = NULL;
        }
        temp[line][col] = '\0';
    }
    temp[line] = '\0';
    return (temp);
}

void update_inventory(game_ *game)
{
    game->clock->time = sfClock_getElapsedTime(game->clock->clock);
    game->clock->secs = game->clock->time.microseconds / 5000;
    if (game->on_inv == 0) {
        sfRenderWindow_drawSprite
        (game->window, game->inv->back->sprite, sfFalse);
    }
}

void create_inventory(game_ *game)
{
    game->inv = malloc(sizeof(inventory_));
    game->inv->page = 0;
    game->inv->back = create_button((sfVector2f){600, 200},
    (sfVector2f){1, 1}, "pictures/menu/inv.png");
    game->inv->inv = malloc_inv();
    game->on_inv = 1;
    game->clock = malloc(sizeof(clock_));
    game->clock->clock = sfClock_create();
}
