/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** mouse_input_grid
*/

#include "../../includes/rpg.h"

void background_or_foreground(game_ *game, grid_cell_ *grid, paint_ *paint,
gen_control_ *gen_control)
{
    sfVector2f sprite_pos = {grid->pos_x, grid->pos_y};
    sfVector2f sprite_scale = {2.5, 2.5};
        grid->foreground->position = sprite_pos;
        grid->foreground_id = gen_control->selected->id;
        grid->foreground->ok = 1;
        grid->foreground->sprite =
        sfSprite_copy(gen_control->selected->sprite);
        sfSprite_setPosition(grid->foreground->sprite, sprite_pos);
        sfSprite_setScale(grid->foreground->sprite, sprite_scale);
}

void left_click_grid(game_ *game, grid_cell_ *grid, paint_ *paint,
gen_control_ *gen_control)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f sprite_pos = {grid->pos_x, grid->pos_y};
    grid->foreground->position = sprite_pos;
    sfVector2f sprite_scale = {2.5, 2.5};

    if (pos_mouse.x > grid->pos_x && pos_mouse.x < grid->pos_x + \
        (40 * paint->scale) && pos_mouse.y > grid->pos_y && pos_mouse.y\
        < grid->pos_y + (40 * paint->scale) && gen_control->sprites_on == 1) {
        grid->click = 1;
        if (gen_control->selected != NULL && gen_control->selected_ == 1) {
            background_or_foreground(game, grid, paint, gen_control);
        }
    }
    if (grid->next_cell != NULL)
        left_click_grid(game, grid->next_cell, paint, gen_control);
}

void right_click_grid(game_ *game, grid_cell_ *grid, paint_ *paint,
gen_control_ *gen_control)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(game->window);

    if (pos_mouse.x > grid->pos_x && pos_mouse.x < grid->pos_x + \
        (40 * paint->scale) && pos_mouse.y > grid->pos_y && pos_mouse.y\
        < grid->pos_y + (40 * paint->scale)) {
        grid->click = 0;
        if (grid->foreground->ok == 1) {
            grid->foreground->sprite = NULL;
            grid->foreground->ok = 0;
        }
    }
    if (grid->next_cell != NULL)
        right_click_grid(game, grid->next_cell, paint, gen_control);
}
