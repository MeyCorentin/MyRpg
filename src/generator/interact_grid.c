/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** interact_grid
*/

#include "../../includes/rpg.h"

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
}

void map_mouse_input(game_ *game, grid_cell_ *grid, paint_ *paint)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        left_click_grid(game, grid, paint);
    if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
        right_click_grid(game, grid, paint);
}
