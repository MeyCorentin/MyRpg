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

    if (grid->foreground->sprite != NULL) {
        grid->foreground->position.y += 40;
        sfSprite_setPosition(grid->foreground->sprite,
        grid->foreground->position);
    }
    if (grid->background->sprite != NULL) {
        grid->background->position.y += 40;
        sfSprite_setPosition(grid->background->sprite,
        grid->background->position);
    }
    if (grid->hitbox->sprite != NULL) {
        grid->hitbox->position.y += 40;
        sfSprite_setPosition(grid->hitbox->sprite,
        grid->hitbox->position);
    }
    if (grid->next_cell != NULL)
        moov_up(grid->next_cell);
}

void moov_down(grid_cell_ *grid)
{
    sfVector2f pos = {grid->pos_x, grid->pos_y - 40};

    grid->pos_y -= 40;
    sfRectangleShape_setPosition(grid->rect, pos);
    if (grid->foreground->sprite != NULL) {
        grid->foreground->position.y -= 40;
        sfSprite_setPosition(grid->foreground->sprite,
        grid->foreground->position);
    }
    if (grid->background->sprite != NULL) {
        grid->background->position.y -= 40;
        sfSprite_setPosition(grid->background->sprite,
        grid->background->position);
    }
    if (grid->hitbox->sprite != NULL) {
        grid->hitbox->position.y -= 40;
        sfSprite_setPosition(grid->hitbox->sprite,
        grid->hitbox->position);
    }
    if (grid->next_cell != NULL)
        moov_down(grid->next_cell);
}

void moov_left(grid_cell_ *grid)
{
    sfVector2f pos = {grid->pos_x + 40, grid->pos_y};

    grid->pos_x += 40;
    sfRectangleShape_setPosition(grid->rect, pos);
    if (grid->foreground->sprite != NULL) {
        grid->foreground->position.x += 40;
        sfSprite_setPosition(grid->foreground->sprite,
        grid->foreground->position);
    }
    if (grid->background->sprite != NULL) {
        grid->background->position.x += 40;
        sfSprite_setPosition(grid->background->sprite,
        grid->background->position);
    }
    if (grid->hitbox->sprite != NULL) {
        grid->hitbox->position.x += 40;
        sfSprite_setPosition(grid->hitbox->sprite,
        grid->hitbox->position);
    }
    if (grid->next_cell != NULL)
        moov_left(grid->next_cell);
}

void moov_right(grid_cell_ *grid)
{
    sfVector2f pos = {grid->pos_x - 40, grid->pos_y};

    grid->pos_x -= 40;
    sfRectangleShape_setPosition(grid->rect, pos);
    if (grid->foreground->sprite != NULL) {
        grid->foreground->position.x -= 40;
        sfSprite_setPosition(grid->foreground->sprite,
        grid->foreground->position);
    }
    if (grid->background->sprite != NULL) {
        grid->background->position.x -= 40;
        sfSprite_setPosition(grid->background->sprite,
        grid->background->position);
    }
    if (grid->hitbox->sprite != NULL) {
        grid->hitbox->position.x -= 40;
        sfSprite_setPosition(grid->hitbox->sprite,
        grid->hitbox->position);
    }
    if (grid->next_cell != NULL)
        moov_right(grid->next_cell);
}

void reset_grid(grid_cell_ *grid)
{
    grid->click = 0;
    grid->background->ok = 1721;
    grid->foreground->ok = 1935;
    grid->hitbox->ok = 1935;
    if (grid->next_cell != NULL)
        reset_grid(grid->next_cell);
}
