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
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            loop_menu(game, game->menu);
        event_cursor(game);
    }
}

void init_map(char ***map, load_map_ *load_map)
{
    int y = 0;
    int x = 0;
    for (y = 0; map[y]; y++) {
        for (x = 0; map[y][x]; x++) {
            init_map_square(map, y, x);
        }
    }
}

void add_tileset(char ***map, sprite_ *sprite, char ***id_background)
{
    int i = 0;
    int j = 0;
    sfVector2f sprite_scale = {2.5, 2.5};
    sfVector2f pos;

    for (; map[i]; i++) {
        for (j = 0; map[i][j] ; j++) {
            if (sprite->id == atoi(id_background[i][j])) {
                pos.x = 40 * j;
                pos.y = 40 * i;
                sfSprite_setScale(sprite->sprite, sprite_scale);
                map[i][j] = (char *)sfSprite_copy(sprite->sprite);
                sfSprite_setPosition((sfSprite *)map[i][j], pos);
            }
        }
    }
    if (sprite->next != NULL)
        add_tileset(map, sprite->next, id_background);
}

void move_map(char ***map, int movement, int y, int x)
{
    sfVector2f pos =
    sfRectangleShape_getPosition((sfRectangleShape *)map[y][x]);

    if (movement == 0)
        pos.y -= 3;
    if (movement == 1)
        pos.x -= 3;
    if (movement == 2)
        pos.y += 3;
    if (movement == 3)
        pos.x += 3;
    sfRectangleShape_setPosition((sfRectangleShape *)map[y][x], pos);
}

void move_background(char ***map, int movement, int y, int x)
{
    sfVector2f pos =
    sfSprite_getPosition((sfSprite *)map[y][x]);

    if (movement == 0)
        pos.y -= 3;
    if (movement == 1)
        pos.x -= 3;
    if (movement == 2)
        pos.y += 3;
    if (movement == 3)
        pos.x += 3;
    sfSprite_setPosition((sfSprite *)map[y][x], pos);
}

void launch_game(game_ *game)
{
    gen_control_ *gen_control = malloc(sizeof(gen_control_));
    sfColor grey = {150, 150, 150, 150};
    load_map_ *load_map = malloc(sizeof(load_map_));
    get_size("background.txt", load_map);
    char ***map = my_malloc_map(load_map->y_size, load_map->x_size);
    char ***map_layer_1 = my_malloc_map_sprite(load_map->y_size, load_map->x_size);
    char ***id_background = get_map(load_map);

    init_map(map, load_map);
    create_gen(gen_control, 1);
    add_tileset(map_layer_1, gen_control->list, id_background);
    create_player(game);
    game->player->movement = 4;
    while (sfRenderWindow_isOpen(game->window)) {
        game->on_button = 1;
        sfRenderWindow_clear(game->window, grey);
        check_event_game(game);
        display_load_map(map, game, game->player->movement);
        display_layer_1(map_layer_1, game, game->player->movement);
        update_player(game, game->player);
        update_cursor(game);
        sfRenderWindow_display(game->window);
    }
}
