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
            + 103 + (55 * line);
            item->line = line;
            item->col = col;
            inv_to_bar(game->first_item, game);
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
    game->clock->check_secs = game->clock->time.microseconds / 5000;
    if (game->boole->on_inv == 0) {
        sfRenderWindow_drawSprite
        (game->window, game->inv->back->sprite, sfFalse);
    }
}

void create_inventory(game_ *game)
{
    game->inv = malloc(sizeof(inventory_));
    game->inv->page = 0;
    game->inv->back = create_button((sfVector2f){660, 200},
    (sfVector2f){1, 1}, "pictures/menu/inv.png");
    game->inv->inv = malloc_inv();
    game->boole->on_inv = 1;
    game->inv->on_item = 1;
    game->inv->bar = create_button((sfVector2f){660, 938}, (sfVector2f){1, 1},
    "pictures/menu/bar.png");
    game->inv->select = create_button((sfVector2f){690, 968},
    (sfVector2f){1, 1}, "pictures/menu/select.png");
    game->clock = malloc(sizeof(clock_));
    game->clock->clock = sfClock_create();
}
