/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** make_grid
*/

#include "../../includes/rpg.h"

void set_gen(game_ *game, paint_ *paint)
{
    paint->scale = 1;
    game->layer = 0;
    sfMusic_stop(game->sounds->ocean);
}

void update_type_layer(game_ *game)
{
    if (game->layer == 0)
        sfText_setString(game->who->text, "BACKGROUND");
    if (game->layer == 1)
        sfText_setString(game->who->text, "FOREGROUND");
    if (game->layer == 2)
        sfText_setString(game->who->text, "HITBOX");
    if (game->layer == 3)
        sfText_setString(game->who->text, "ENNEMYS");
    sfRenderWindow_drawText(game->window, game->who->text, sfFalse);
}

void launch_map_generator(game_ *game)
{
    paint_ *paint = malloc(sizeof(paint_));
    grid_cell_ *grid = malloc(sizeof(grid_cell_));
    gen_control_ *gen_control = malloc(sizeof(gen_control_));
    sfRectangleShape *rect = sfRectangleShape_create();

    set_gen(game, paint);
    init_rect(grid, rect, 30, 50);
    create_map(game, grid, 30, 50);
    create_gen(gen_control, 1);
    game->who = create_text("BACKGROUND", (sfVector2f){2, 2}, (sfVector2f){10, 5}, "font/Stardew_Valley.ttf");
    while (sfRenderWindow_isOpen(game->window)) {
        game->mouse = sfMouse_getPositionRenderWindow(game->window);
        sfRenderWindow_clear(game->window, (sfColor){150, 150, 150, 150});
        check_event_gen(game, gen_control, paint);
        map_key_input(game, grid, gen_control);
        map_mouse_input(game, grid, paint, gen_control);
        display_all(game, grid, gen_control, paint);
        interact_sprite(game, gen_control->list, gen_control);
        update_type_layer(game);
        sfRenderWindow_display(game->window);
    }
}
