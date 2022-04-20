/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void init_layer_1(layer_ *layer, load_map_ *load_map,
gen_control_ *gen_control, game_ *game)
{
    get_size("background.txt", load_map);
    get_size_2("test.txt", load_map);
    get_size_3("hitbox.txt", load_map);
    create_gen(gen_control, 1);
    layer->map = my_malloc_map(load_map->y_size, load_map->x_size);
    layer->map_layer_1 =
    my_malloc_map_sprite(load_map->y_size, load_map->x_size);
    layer->id_background = get_map(load_map);
    init_map(layer->map, load_map);
    add_tileset(layer->map_layer_1, gen_control->list, layer->id_background);
}

void init_layer_2(layer_ *layer, load_map_ *load_map,
gen_control_ *gen_control, game_ *game)
{
    get_size("background.txt", load_map);
    get_size_2("test.txt", load_map);
    get_size_3("hitbox.txt", load_map);
    create_gen(gen_control, 1);
    layer->map_2 = my_malloc_map(load_map->y_size, load_map->x_size);
    layer->map_layer_2 =
    my_malloc_map_sprite(load_map->y_size, load_map->x_size);
    layer->id_foreground = get_map_2(load_map);
    init_map(layer->map_2, load_map);
    add_tileset_2(layer->map_layer_2, gen_control->list, layer->id_foreground);
}

void init_layer_3(layer_ *layer, load_map_ *load_map,
gen_control_ *gen_control, game_ *game)
{
    get_size("background.txt", load_map);
    get_size_2("test.txt", load_map);
    get_size_3("hitbox.txt", load_map);
    create_gen(gen_control, 1);
    layer->map_3 = my_malloc_map(load_map->y_size, load_map->x_size);
    layer->map_layer_3 =
    my_malloc_map_sprite(load_map->y_size, load_map->x_size);
    layer->id_hitbox = get_map_3(load_map);
    init_map(layer->map_3, load_map);
    create_gen(gen_control, 1);
    add_tileset_2(layer->map_layer_3, gen_control->list, layer->id_hitbox);
}

void init_layer(layer_ *layer, load_map_ *load_map, gen_control_ *gen_control
, game_ *game)
{
    init_layer_1(layer, load_map, gen_control, game);
    init_layer_2(layer, load_map, gen_control, game);
    init_layer_3(layer, load_map, gen_control, game);
}
