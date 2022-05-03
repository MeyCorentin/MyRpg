/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** init_map_mob
*/

#include "../../includes/rpg.h"

void init_map_mob_3(int y, int x, layer_ *layer, game_ *game)
{
    sfVector2f pos = {40 * x, 40 * y};
    pos.x += game->x_start;
    pos.y += game->y_start;

    switch (my_atoi(layer->id_mob[y][x])) {
        case (12): get_last_e(game->first, pos, (sfIntRect)
            {364, 3252, 16, 32}, 436); break;
        case (13): get_last_e(game->first, pos, (sfIntRect)
            {364, 3711, 16, 32}, 436); break;
        case (14): get_last_e(game->first, pos, (sfIntRect)
            {364, 4204, 16, 32}, 436); break;
        case (15): get_last_e(game->first, pos, (sfIntRect)
            {364, 4690, 16, 32}, 436); break;
    }
}

void init_map_mob_2(int y, int x, layer_ *layer, game_ *game)
{
    sfVector2f pos = {40 * x, 40 * y};
    pos.x += game->x_start;
    pos.y += game->y_start;

    switch (my_atoi(layer->id_mob[y][x])) {
        case (7): get_last_e(game->first, pos, (sfIntRect)
            {22, 871, 16, 32}, 100); break;
        case (8): get_last_e(game->first, pos, (sfIntRect)
            {364, 1505, 16, 32}, 436); break;
        case (9): get_last_e(game->first, pos, (sfIntRect)
            {364, 1613, 16, 32}, 436); break;
        case (10): get_last_e(game->first, pos, (sfIntRect)
            {365, 2200, 16, 32}, 437); break;
        case (11): get_last_e(game->first, pos, (sfIntRect)
            {364, 2728, 16, 32}, 436); break;
        default: init_map_mob_3(y, x, layer, game);
    }
}

void init_map_mob(int y, int x, layer_ *layer, game_ *game)
{
    sfVector2f pos = {40 * x, 40 * y};
    pos.x += game->x_start;
    pos.y += game->y_start;

    switch (my_atoi(layer->id_mob[y][x])) {
        case (1): get_last_e(game->first, pos, (sfIntRect)
            {22, 50, 16, 16}, 100); break;
        case (2): get_last_e(game->first, pos, (sfIntRect)
            {22, 145, 16, 16}, 100); break;
        case (3): get_last_e(game->first, pos, (sfIntRect)
            {22, 334, 16, 32}, 100); break;
        case (4): get_last_e(game->first, pos, (sfIntRect)
            {22, 480, 16, 32}, 100); break;
        case (5): get_last_e(game->first, pos, (sfIntRect)
            {27, 695, 16, 16}, 105); break;
        case (6): get_last_e(game->first, pos, (sfIntRect)
            {27, 775, 16, 16}, 105); break;
        default: init_map_mob_2(y, x, layer, game);
    }
}
