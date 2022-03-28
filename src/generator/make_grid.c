/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** make_grid
*/

#include "../../includes/rpg.h"

void init_rect_2(grid_cell_ *grid, sfRectangleShape *rect, int x, int y)
{
    grid->foreground = malloc(sizeof(sprite_));
    grid->foreground->sprite = NULL;
    grid->foreground->ok = 0;
    grid->background = malloc(sizeof(sprite_));
    grid->background->sprite = NULL;
    grid->background->ok = 0;
    grid->l_pos = 1;
    grid->g_pos = 1;
    grid->next_cell = NULL;
}

void init_rect(grid_cell_ *grid, sfRectangleShape *rect, int x, int y)
{
    sfVector2f size = {40, 40};
    sfVector2f pos = {0, 0};

    grid->rect = rect;
    grid->prev_cell = NULL;
    grid->pos_x = 0;
    grid->pos_y = 0;
    grid->click = 0;
    grid->size_x = x;
    grid->foreground_id = 0000;
    grid->background_id = 0000;
    grid->size_y = y;
    sfRectangleShape_setSize(grid->rect, size);
    sfRectangleShape_setFillColor(grid->rect, sfWhite);
    sfRectangleShape_setPosition(grid->rect, pos);
    init_rect_2(grid, rect, x, y);
}

void create_foreground_background(struct grid_cell *new)
{
    new->foreground_id = 0000;
    new->background_id = 0000;
    new->foreground = malloc(sizeof(sprite_));
    new->foreground->sprite = NULL;
    new->foreground->ok = 0;
    new->background = malloc(sizeof(sprite_));
    new->background->sprite = NULL;
    new->background->ok = 0;
}

void create_map(game_ *game, struct grid_cell *grid, int x, int y)
{
    grid_cell_ *new = malloc(sizeof(grid_cell_));
    sfVector2f size = {40, 40};
    sfVector2f pos = {40 * grid->l_pos, 40 * (grid->g_pos / x)};

    new->size_x = x;
    new->size_y = y;
    new->pos_x = 40 * grid->l_pos,
    new->pos_y = 40 * (grid->g_pos / x);
    new->rect = sfRectangleShape_create();
    new->click = 0;
    sfRectangleShape_setSize(new->rect, size);
    sfRectangleShape_setPosition(new->rect, pos);
    new->l_pos = grid->l_pos + 1;
    (new->l_pos > x - 1) ? new->l_pos = 0 : 1;
    new->g_pos = grid->g_pos + 1;
    new->next_cell = NULL;
    new->prev_cell = grid;
    create_foreground_background(new);
    grid->next_cell = new;
    (grid->g_pos != (x * y) - 1) ? create_map(game, grid->next_cell, x, y) : 1;
}

void launch_map_generator(game_ *game)
{
    paint_ *paint = malloc(sizeof(paint_));
    grid_cell_ *grid = malloc(sizeof(grid_cell_));
    gen_control_ *gen_control = malloc(sizeof(gen_control_));
    sfRectangleShape *rect = sfRectangleShape_create();
    sfColor color = {150, 150, 150, 150};

    paint->scale = 1;
    init_rect(grid, rect, 15, 15);
    create_map(game, grid, 15, 15);
    create_gen(gen_control);
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, color);
        check_event_gen(game, gen_control, paint);
        map_key_input(game, grid);
        map_mouse_input(game, grid, paint, gen_control);
        display_all(game, grid, gen_control, paint);
        interact_sprite(game, gen_control->list, gen_control);
        draw_sprites_gen(game, gen_control);
        sfRenderWindow_display(game->window);
    }
}
