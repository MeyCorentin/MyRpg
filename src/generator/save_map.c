/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** interact_grid
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../../includes/rpg.h"

void save_foreground(game_ *game, grid_cell_ *grid, FILE *file)
{
    fwrite("[", 1, my_strlen("["), file);
    fwrite(new_put_nbr(grid->foreground_id), 1,
    my_strlen(new_put_nbr(grid->foreground_id) + 1), file);
    fwrite("]", 1, my_strlen("]"), file);
    if (grid->g_pos % grid->size_x == 0 && grid->g_pos
        != grid->size_x * grid->size_y)
        fwrite("\n", 1, my_strlen("\n"), file);
    if (grid->g_pos == grid->size_x * grid->size_y)
        fwrite("\0", 1, my_strlen("\0"), file);
    if (grid->next_cell != NULL)
        save_foreground(game, grid->next_cell, file);
}

void save_background(game_ *game, grid_cell_ *grid, FILE *file)
{
    fwrite("[", 1, my_strlen("["), file);
    fwrite(new_put_nbr(grid->background_id), 1,
    my_strlen(new_put_nbr(grid->background_id) + 1), file);
    fwrite("]", 1, my_strlen("]"), file);
    if (grid->g_pos % grid->size_x == 0 && grid->g_pos
        != grid->size_x * grid->size_y)
        fwrite("\n", 1, my_strlen("\n"), file);
    if (grid->g_pos == grid->size_x * grid->size_y)
        fwrite("\0", 1, my_strlen("\0"), file);
    if (grid->next_cell != NULL)
        save_background(game, grid->next_cell, file);
}
