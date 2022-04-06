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

void page_handle(gen_control_ *gen_control)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum1)) {
        create_gen(gen_control, 1);
        gen_control->sprites_on = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum2)) {
        create_gen(gen_control, 2);
        gen_control->sprites_on = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum3)) {
        create_gen(gen_control, 3);
        gen_control->sprites_on = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum4)) {
        create_gen(gen_control, 4);
        gen_control->sprites_on = 0;
    }
}

void map_key_moov(game_ *game, grid_cell_ *grid, gen_control_ *gen_control)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        (gen_control->sprites_on == 0) ? moov_up_gen(gen_control->list) :
        moov_up(grid);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        (gen_control->sprites_on == 0) ? moov_down_gen(gen_control->list) :
        moov_down(grid);
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        (gen_control->sprites_on == 0) ? moov_right_gen(gen_control->list) :
        moov_left(grid);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        (gen_control->sprites_on == 0) ? moov_left_gen(gen_control->list) :
        moov_right(grid);
    }
}

void map_key_input(game_ *game, grid_cell_ *grid, gen_control_ *gen_control)
{
    map_key_moov(game, grid, gen_control);
    (sfKeyboard_isKeyPressed(sfKeyR)) ? reset_grid(grid) : 1;
    (sfKeyboard_isKeyPressed(sfKeyEnter)) ? save_all(game, grid) : 1;
    (sfKeyboard_isKeyPressed(sfKeyUp)) ? game->layer = 1 : 1;
    (sfKeyboard_isKeyPressed(sfKeyDown)) ? game->layer = 0 : 1;
    page_handle(gen_control);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
            loop_menu(game, game->menu);
}

void map_mouse_input(game_ *game, grid_cell_ *grid,
paint_ *paint, gen_control_ *gen_control)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        left_click_grid(game, grid, paint, gen_control);
    if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
        right_click_grid(game, grid, paint, gen_control);
}
