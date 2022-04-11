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
        if (sfKeyboard_isKeyPressed(sfKeyEscape) && game->on_inv == 1) {
            sfMusic_stop(game->sounds->summer_day);
            loop_menu(game, game->menu);
        }
        open_close_inv(game);
        event_cursor(game);
        move_select(game);
        check_event_items(game);
    }
}

void launch_layer(game_ *game, layer_ *layer, sfVector2f pos, sfSprite *rep)
{
    move_rep(rep, game->player->movement);
    display_load_map(layer->map, game, game->player->movement);
    display_layer(layer->map_layer_1, game, game->player->movement);
    if (atoi(layer->id_foreground[(int)((500 - pos.y + 120) / 40)]
    [(int)((950 - pos.x) / 40)]) != 1945 ||
    atoi(layer->id_foreground[(int)((500 - pos.y + 120) / 40)]
    [(int)((950 - pos.x - 80) / 40)]) != 1945) {
        update_bar(game);
        update_player(game, game->player);
        display_layer(layer->map_layer_2, game, game->player->movement);
    } else {
        display_layer(layer->map_layer_2, game, game->player->movement);
        update_bar(game);
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
