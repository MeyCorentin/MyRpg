/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** make_grid
*/

#include "../../includes/rpg.h"

void display_square(game_ *game, grid_cell_ *grid, gen_control_ *gen_control,
paint_ *paint)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(game->window);

    if (pos_mouse.x > grid->pos_x && pos_mouse.x < grid->pos_x +
        (40 * paint->scale) &&
        pos_mouse.y > grid->pos_y && pos_mouse.y < grid->pos_y +
        (40 * paint->scale)) {
        if (grid->click == 0 && gen_control->sprites_on != 0)
            sfRectangleShape_setFillColor(grid->rect, sfGreen);
        } else {
            sfRectangleShape_setFillColor(grid->rect, sfWhite);
    }
    if (grid->click == 1 && grid->foreground->sprite == NULL &&
    grid->background->sprite == NULL)
        sfRectangleShape_setFillColor(grid->rect, sfBlue);
    sfRenderWindow_drawRectangleShape(game->window, grid->rect, sfFalse);
    if (grid->next_cell != NULL)
        display_square(game, grid->next_cell, gen_control, paint);
}

void display_foreground(game_ *game, grid_cell_ *grid,
gen_control_ *gen_control, paint_ *paint)
{
    if (grid->foreground->ok == 1)
        sfRenderWindow_drawSprite(game->window, grid->foreground->sprite,
        sfFalse);
    if (grid->next_cell != NULL)
        display_foreground(game, grid->next_cell, gen_control, paint);
}

void display_background(game_ *game, grid_cell_ *grid,
gen_control_ *gen_control, paint_ *paint)
{
    if (grid->background->ok == 1)
        sfRenderWindow_drawSprite(game->window, grid->background->sprite,
        sfFalse);
    if (grid->next_cell != NULL)
        display_background(game, grid->next_cell, gen_control, paint);
}

void draw_env(game_ *game, sprite_ *sprite)
{
    sfRenderWindow_drawSprite(game->window, sprite->sprite, sfFalse);
    if (sprite->next != NULL)
        draw_env(game, sprite->next);
}

void display_all(game_ *game, grid_cell_ *grid,
gen_control_ *gen_control, paint_ *paint)
{
    display_square(game, grid, gen_control, paint);
    display_background(game, grid, gen_control, paint);
    display_foreground(game, grid, gen_control, paint);
}
