/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** moov_grid
*/

#include "../../includes/rpg.h"

void moov_up(grid_cell_ *grid)
{
    sfVector2f pos = {grid->pos_x, grid->pos_y + 40};

    grid->pos_y += 40;
    sfRectangleShape_setPosition(grid->rect, pos);
    if (grid->next_cell != NULL)
        moov_up(grid->next_cell);
}

void moov_down(grid_cell_ *grid)
{
    sfVector2f pos = {grid->pos_x, grid->pos_y - 40};

    grid->pos_y -= 40;
    sfRectangleShape_setPosition(grid->rect, pos);
    if (grid->next_cell != NULL)
        moov_down(grid->next_cell);
}

void moov_left(grid_cell_ *grid)
{
    sfVector2f pos = {grid->pos_x + 40, grid->pos_y};

    grid->pos_x += 40;
    sfRectangleShape_setPosition(grid->rect, pos);
    if (grid->next_cell != NULL)
        moov_left(grid->next_cell);
}

void moov_right(grid_cell_ *grid)
{
    sfVector2f pos = {grid->pos_x - 40, grid->pos_y};

    grid->pos_x -= 40;
    sfRectangleShape_setPosition(grid->rect, pos);
    if (grid->next_cell != NULL)
        moov_right(grid->next_cell);
}

void reset_grid(grid_cell_ *grid)
{
    grid->click = 0;
    if (grid->next_cell != NULL)
        reset_grid(grid->next_cell);
}
