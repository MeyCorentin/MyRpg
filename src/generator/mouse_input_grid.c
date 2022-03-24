/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** mouse_input_grid
*/

#include "../../includes/rpg.h"

void left_click_grid(game_ *game, grid_cell_ *grid, paint_ *paint)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(game->window);

    if (pos_mouse.x > grid->pos_x && pos_mouse.x < grid->pos_x + \
        (40 * paint->scale) && pos_mouse.y > grid->pos_y && pos_mouse.y\
        < grid->pos_y + (40 * paint->scale)) {
        grid->click = 1;
    }
    if (grid->next_cell != NULL)
        left_click_grid(game, grid->next_cell, paint);
}

void right_click_grid(game_ *game, grid_cell_ *grid, paint_ *paint)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(game->window);

    if (pos_mouse.x > grid->pos_x && pos_mouse.x < grid->pos_x + \
        (40 * paint->scale) && pos_mouse.y > grid->pos_y && pos_mouse.y\
        < grid->pos_y + (40 * paint->scale)) {
        grid->click = 0;
    }
    if (grid->next_cell != NULL)
        right_click_grid(game, grid->next_cell, paint);
}
