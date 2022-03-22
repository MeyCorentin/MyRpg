/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** make_grid
*/

#include "../../includes/rpg.h"

void init_rect(grid_cell_ *grid, sfRectangleShape *rect)
{
    sfVector2f size = {40, 40};
    sfVector2f pos = {0, 0};
    sfColor color = {255, 255, 255, 255};

    grid->rect = rect;
    grid->prev_cell = NULL;
    grid->pos_x = 0;
    grid->pos_y = 0;
    grid->click = 0;
    sfRectangleShape_setSize(grid->rect, size);
    sfRectangleShape_setFillColor(grid->rect, color);
    sfRectangleShape_setPosition(grid->rect, pos);
    grid->l_pos = 1;
    grid->g_pos = 1;
    grid->next_cell = NULL;
}

void create_map(game_ *game, struct grid_cell *grid, int x, int y)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    grid_cell_ *new = malloc(sizeof(grid_cell_));
    sfVector2f size = {40, 40};
    sfVector2f pos = {40 * grid->l_pos, 40 * (grid->g_pos / x)};

    new->pos_x = 40 * grid->l_pos,
    new->pos_y = 40 * (grid->g_pos / x);
    new->rect = rect;
    new->click = 0;
    sfRectangleShape_setSize(new->rect, size);
    sfRectangleShape_setPosition(new->rect, pos);
    new->l_pos = grid->l_pos + 1;
    if (new->l_pos > x - 1)
        new->l_pos = 0;
    new->g_pos = grid->g_pos + 1;
    new->next_cell = NULL;
    new->prev_cell = grid;
    grid->next_cell = new;
    if (grid->g_pos != (x * y) - 1)
        create_map(game, grid->next_cell, x, y);
}

void display_map(game_ *game, grid_cell_ *grid)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(game->window);

    if (pos_mouse.x > grid->pos_x && pos_mouse.x < grid->pos_x + 40 &&
        pos_mouse.y > grid->pos_y && pos_mouse.y < grid->pos_y + 40) {
        if (grid->click != 1)
            sfRectangleShape_setFillColor(grid->rect, sfGreen);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            grid->click = 1;
            sfRectangleShape_setFillColor(grid->rect, sfBlue);
        }
        sfRenderWindow_drawRectangleShape(game->window, grid->rect, sfFalse);
    } else {
        if (grid->click != 1)
            sfRectangleShape_setFillColor(grid->rect, sfWhite);
        sfRenderWindow_drawRectangleShape(game->window, grid->rect, sfFalse);
    }
    if (grid->next_cell != NULL)
        display_map(game, grid->next_cell);
}

void launch_map_generator(game_ *game)
{
    grid_cell_ *grid = malloc(sizeof(grid_cell_));
    sfRectangleShape *rect = sfRectangleShape_create();

    init_rect(grid, rect);
    create_map(game, grid, 10, 5);
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfGreen);
        check_event_game(game);
        moov_map(game, grid);
        display_map(game, grid);
        sfRenderWindow_display(game->window);
    }
}
