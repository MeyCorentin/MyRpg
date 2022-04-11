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
    sfColor hit = {255, 0, 0, 150};
    if (game->layer == 0) {
        grid->background->position = sprite_pos;
        grid->background_id = gen_control->selected->id;
        grid->background->ok = 1;
        grid->background->sprite =
        sfSprite_copy(gen_control->selected->sprite);
        sfSprite_setPosition(grid->background->sprite, sprite_pos);
        sfSprite_setScale(grid->background->sprite, sprite_scale);
    }
    if (game->layer == 1) {
        grid->foreground->position = sprite_pos;
        grid->foreground_id = gen_control->selected->id;
        grid->foreground->ok = 1;
        grid->foreground->sprite =
        sfSprite_copy(gen_control->selected->sprite);
        sfSprite_setPosition(grid->foreground->sprite, sprite_pos);
        sfSprite_setScale(grid->foreground->sprite, sprite_scale);
    }
    if (game->layer == 2) {
        grid->hitbox->position = sprite_pos;
        grid->hitbox_id = 6666;
        grid->hitbox->ok = 1;
        grid->hitbox->sprite =
        sfSprite_copy(gen_control->selected->sprite);
        sfSprite_setPosition(grid->hitbox->sprite, sprite_pos);
        sfSprite_setScale(grid->hitbox->sprite, sprite_scale);
        sfSprite_setColor(grid->hitbox->sprite, hit);
    }
}

void left_click_grid(game_ *game, grid_cell_ *grid, paint_ *paint,
gen_control_ *gen_control)
{
    sfVector2f sprite_pos = {grid->pos_x, grid->pos_y};
    grid->foreground->position = sprite_pos;
    sfVector2f sprite_scale = {2.5, 2.5};

    if (game->mouse.x > grid->pos_x && game->mouse.x < grid->pos_x + \
        (40 * paint->scale) && game->mouse.y > grid->pos_y && game->mouse.y\
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
    if (game->mouse.x > grid->pos_x && game->mouse.x < grid->pos_x + \
        (40 * paint->scale) && game->mouse.y > grid->pos_y && game->mouse.y\
        < grid->pos_y + (40 * paint->scale)) {
        grid->click = 0;
        if (game->layer == 1) {
            (grid->foreground->ok == 1) ? grid->foreground->sprite = NULL,
            grid->foreground->ok = 0 : 1;
        }
        if (game->layer == 0) {
            (grid->background->ok == 1) ? grid->background->sprite = NULL,
            grid->background->ok = 0 : 1;
        }
    }
    if (grid->next_cell != NULL)
        right_click_grid(game, grid->next_cell, paint, gen_control);
}
