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

void print_size(game_ *game, grid_cell_ *grid, FILE *file)
{
    fwrite(new_put_nbr(grid->size_y), 1,
    my_strlen(new_put_nbr(grid->size_y)), file);
    fwrite(" ", 1, my_strlen(" "), file);
    fwrite(new_put_nbr(grid->size_x), 1,
    my_strlen(new_put_nbr(grid->size_x)), file);
    fwrite("\n", 1, my_strlen("\n"), file);
}

void save_all(game_ *game, grid_cell_ *grid)
{
    FILE *foreground_file = fopen("foreground.txt", "wa");
    print_size(game, grid, foreground_file);
    save_foreground(game, grid, foreground_file);
    fclose(foreground_file);
    FILE *test = fopen("test.txt", "wa");
    print_size(game, grid, test);
    save_foreground(game, grid, test);
    fclose(test);
    FILE *background_file = fopen("background.txt", "wa");
    print_size(game, grid, background_file);
    save_background(game, grid, background_file);
    fclose(background_file);
    FILE *hitbox_file = fopen("hitbox.txt", "wa");
    print_size(game, grid, background_file);
    save_hitbox(game, grid, background_file);
    fclose(background_file);
}

void save_hitbox(game_ *game, grid_cell_ *grid, FILE *file)
{
    fwrite("[", 1, my_strlen("["), file);
    fwrite(new_put_nbr(grid->hitbox_id), 1,
    my_strlen(new_put_nbr(grid->hitbox_id)), file);
    fwrite("]", 1, my_strlen("]"), file);
    if (grid->g_pos % grid->size_x == 0 && grid->g_pos
        != grid->size_x * grid->size_y)
        fwrite("\n", 1, my_strlen("\n"), file);
    if (grid->g_pos == grid->size_x * grid->size_y)
        fwrite("\0", 1, my_strlen("\0"), file);
    if (grid->next_cell != NULL)
        save_hitbox(game, grid->next_cell, file);
}

void save_foreground(game_ *game, grid_cell_ *grid, FILE *file)
{
    fwrite("[", 1, my_strlen("["), file);
    fwrite(new_put_nbr(grid->foreground_id), 1,
    my_strlen(new_put_nbr(grid->foreground_id)), file);
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
    my_strlen(new_put_nbr(grid->background_id)), file);
    fwrite("]", 1, my_strlen("]"), file);
    if (grid->g_pos % grid->size_x == 0 && grid->g_pos
        != grid->size_x * grid->size_y)
        fwrite("\n", 1, my_strlen("\n"), file);
    if (grid->g_pos == grid->size_x * grid->size_y)
        fwrite("\0", 1, my_strlen("\0"), file);
    if (grid->next_cell != NULL)
        save_background(game, grid->next_cell, file);
}
