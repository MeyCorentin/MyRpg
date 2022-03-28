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
    FILE *background_file = fopen("background.txt", "wa");
    print_size(game, grid, background_file);
    save_background(game, grid, background_file);
    fclose(background_file);
}

void map_key_input(game_ *game, grid_cell_ *grid)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        moov_up(grid);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        moov_down(grid);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        moov_left(grid);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        moov_right(grid);
    if (sfKeyboard_isKeyPressed(sfKeyR))
        reset_grid(grid);
    if (sfKeyboard_isKeyPressed(sfKeyEnter))
        save_all(game, grid);
}

void map_mouse_input(game_ *game, grid_cell_ *grid,
paint_ *paint, gen_control_ *gen_control)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        left_click_grid(game, grid, paint, gen_control);
    if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
        right_click_grid(game, grid, paint, gen_control);
}
