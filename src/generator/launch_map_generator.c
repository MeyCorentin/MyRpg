/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** make_grid
*/

#include "../../includes/rpg.h"

void launch_map_generator(game_ *game)
{
    paint_ *paint = malloc(sizeof(paint_));
    grid_cell_ *grid = malloc(sizeof(grid_cell_));
    gen_control_ *gen_control = malloc(sizeof(gen_control_));
    sfRectangleShape *rect = sfRectangleShape_create();
    sfColor color = {150, 150, 150, 150};

    paint->scale = 1;
    init_rect(grid, rect, 21, 21);
    create_map(game, grid, 21, 21);
    create_gen(gen_control, 1);
    game->layer = 0;
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, color);
        check_event_gen(game, gen_control, paint);
        map_key_input(game, grid, gen_control);
        map_mouse_input(game, grid, paint, gen_control);
        display_all(game, grid, gen_control, paint);
        interact_sprite(game, gen_control->list, gen_control);
        sfRenderWindow_display(game->window);
    }
}
