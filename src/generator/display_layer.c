/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** make_grid
*/

#include "../../includes/rpg.h"

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

void display_hitbox(game_ *game, grid_cell_ *grid,
gen_control_ *gen_control, paint_ *paint)
{
    if (grid->hitbox->ok == 1)
        sfRenderWindow_drawSprite(game->window, grid->hitbox->sprite,
        sfFalse);
    if (grid->next_cell != NULL)
        display_hitbox(game, grid->next_cell, gen_control, paint);
}
