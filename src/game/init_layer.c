/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void init_layer_1(layer_ *layer, load_map_ *load_map,
gen_control_ *gen_control, int season)
{
    get_size("background.txt", load_map);
    get_size_2("test.txt", load_map);
    get_size_3("hitbox.txt", load_map);
    create_gen(gen_control, 1);
    char ***map = my_malloc_map(load_map->y_size, load_map->x_size);
    sfSprite ***map_layer_1 =
    my_malloc_map_sprite(load_map->y_size, load_map->x_size);
    char ***id_background = get_map(load_map);
    init_map(map, load_map);
    add_tileset(map_layer_1, gen_control->list, id_background);
    layer->map = map;
    layer->map_layer_1 = map_layer_1;
    layer->id_background = id_background;
}

void init_layer_2(layer_ *layer, load_map_ *load_map,
gen_control_ *gen_control, int season)
{
    get_size("background.txt", load_map);
    get_size_2("test.txt", load_map);
    get_size_3("hitbox.txt", load_map);
    create_gen(gen_control, 1);
    char ***map_2 = my_malloc_map(load_map->y_size, load_map->x_size);
    sfSprite ***map_layer_2 =
    my_malloc_map_sprite(load_map->y_size, load_map->x_size);
    char ***id_foreground = get_map_2(load_map);
    init_map(map_2, load_map);
    add_tileset_2(map_layer_2, gen_control->list, id_foreground);
    layer->map_2 = map_2;
    layer->map_layer_2 = map_layer_2;
    layer->id_foreground = id_foreground;
}

void init_layer_3(layer_ *layer, load_map_ *load_map,
gen_control_ *gen_control, int season)
{
    get_size("background.txt", load_map);
    get_size_2("test.txt", load_map);
    get_size_3("hitbox.txt", load_map);
    create_gen(gen_control, 1);
    char ***map_3 = my_malloc_map(load_map->y_size, load_map->x_size);
    sfSprite ***map_layer_3 =
    my_malloc_map_sprite(load_map->y_size, load_map->x_size);
    char ***id_hitbox = get_map_3(load_map);
    init_map(map_3, load_map);
    create_gen(gen_control, 1);
    add_tileset_2(map_layer_3, gen_control->list, id_hitbox);
    layer->map_3 = map_3;
    layer->map_layer_3 = map_layer_3;
    layer->id_hitbox = id_hitbox;
}

void init_layer(layer_ *layer, load_map_ *load_map, gen_control_ *gen_control,
int season)
{
    init_layer_1(layer, load_map, gen_control, season);
    init_layer_2(layer, load_map, gen_control, season);
    init_layer_3(layer, load_map, gen_control, season);
}
