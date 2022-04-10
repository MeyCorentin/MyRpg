/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void check_event_game(game_ *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        game->mouse = sfMouse_getPositionRenderWindow(game->window);
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        (sfKeyboard_isKeyPressed(sfKeyEscape)) ?
        sfMusic_stop(game->sounds->summer_day),
        loop_menu(game, game->menu) : 1;
        if (game->on_inv == 1 && sfKeyboard_isKeyPressed(sfKeyI) &&
        game->clock->secs != 0) {
            game->clock->secs = 0;
            game->on_inv = 0;
        }
        if (game->on_inv == 0 && sfKeyboard_isKeyPressed(sfKeyI) &&
        game->clock->secs != 0) {
            game->clock->secs = 0;
            game->on_inv = 1;
        }
        event_cursor(game);
        check_on_item(game, game->first_item, game->player);
    }
}

void init_layer(layer_ *layer, load_map_ *load_map, gen_control_ *gen_control)
{
    char ***map = my_malloc_map(load_map->y_size, load_map->x_size);
    char ***map_2 = my_malloc_map(load_map->y_size, load_map->x_size);
    char ***map_layer_1 =
    my_malloc_map_sprite(load_map->y_size, load_map->x_size);
    char ***map_layer_2 =
    my_malloc_map_sprite(load_map->y_size, load_map->x_size);
    char ***id_background = get_map(load_map);
    char ***id_foreground = get_map_2(load_map);

    init_map(map, load_map);
    init_map(map_2, load_map);
    create_gen(gen_control, 1);
    add_tileset(map_layer_1, gen_control->list, id_background);
    add_tileset_2(map_layer_2, gen_control->list, id_foreground);
    layer->map = map;
    layer->map_2 = map_2;
    layer->map_layer_1 = map_layer_1;
    layer->map_layer_2 = map_layer_2;
    layer->id_background = id_background;
    layer->id_foreground = id_foreground;
}

void launch_layer(game_ *game, layer_ *layer, sfVector2f pos, sfSprite *rep)
{
    move_rep(rep, game->player->movement);
    display_load_map(layer->map, game, game->player->movement);
    display_layer_1(layer->map_layer_1, game, game->player->movement);
    if (atoi(layer->id_foreground[(int)((500 - pos.y + 120) / 40)]
    [(int)((950 - pos.x) / 40)]) != 1945 ||
    atoi(layer->id_foreground[(int)((500 - pos.y + 120) / 40)]
    [(int)((950 - pos.x - 80) / 40)]) != 1945) {
        if (game->on_inv == 1)
            draw_items(game, game->first_item, game->player->movement, 1);
        update_player(game, game->player);
        display_layer_2(layer->map_layer_2, game,
        game->player->movement, game->player);
    } else {
        display_layer_2(layer->map_layer_2, game,
        game->player->movement, game->player);
        if (game->on_inv == 1)
            draw_items(game, game->first_item, game->player->movement, 1);
        update_player(game, game->player);
    }
    update_inv(game);
}

void set_game(game_ *game)
{
    create_player(game);
    game->player->movement = 4;
    game->first_item = NULL;
    sfMusic_stop(game->sounds->ocean);
    sfMusic_play(game->sounds->summer_day);
    create_inventory(game);
}

void launch_game(game_ *game)
{
    layer_ *layer = malloc(sizeof(layer_));
    gen_control_ *gen_control = malloc(sizeof(gen_control_));
    load_map_ *load_map = malloc(sizeof(load_map_));
    sfSprite *rep = sfSprite_create();
    get_size("background.txt", load_map);
    get_size_2("test.txt", load_map);
    init_layer(layer, load_map, gen_control);
    set_game(game);
    add_items(game, game->first_item);
    add_items(game, game->first_item);
    while (sfRenderWindow_isOpen(game->window)) {
        game->mouse = sfMouse_getPositionRenderWindow(game->window);
        sfVector2f pos = sfSprite_getPosition(rep);
        game->on_button = 1;
        sfRenderWindow_clear(game->window, (sfColor){150, 150, 150, 150});
        check_event_game(game);
        launch_layer(game, layer, pos, rep);
        sfRenderWindow_display(game->window);
    }
}
