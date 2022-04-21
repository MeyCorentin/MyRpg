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
        if (game->event.type == sfEvtClosed) {
            sfMusic_stop(game->sounds->summer_day);
            sfRenderWindow_close(game->window);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape) && game->boole->on_inv == 1
        && game->clock->check_secs != 0) {
            sfMusic_stop(game->sounds->summer_day);
            loop_menu(game, game->menu);
        }
        open_close_hint(game);
        event_cursor(game);
        move_select(game);
        check_event_items(game);
        open_close_inv(game);
        open_close_best(game);
    }
}

void set_game(game_ *game)
{
    create_player(game);
    create_bonus(game);
    game->player->movement = 4;
    game->first_item = NULL;
    sfMusic_stop(game->sounds->ocean);
    sfMusic_play(game->sounds->summer_day);
    create_inventory(game);
    create_bestiary(game);
    create_ath(game);
    create_tree(game);
    create_life(game);
    game->boole->on_tree = 1;
    game->boole->on_hint = 0;
}

void launch_game(game_ *game)
{
    layer_ *layer = malloc(sizeof(layer_));
    gen_control_ *gen_control = malloc(sizeof(gen_control_));
    load_map_ *load_map = malloc(sizeof(load_map_));
    sfSprite *rep = sfSprite_create();
    game->layer_ = layer;
    init_layer(layer, load_map, gen_control, game);
    set_game(game);
    add_items(game, game->first_item);
    add_items(game, game->first_item);
    while (sfRenderWindow_isOpen(game->window)) {
        game->mouse = sfMouse_getPositionRenderWindow(game->window);
        sfVector2f pos = sfSprite_getPosition(rep);
        game->boole->on_button = 1;
        sfRenderWindow_clear(game->window, (sfColor){150, 150, 150, 150});
        check_event_game(game);
        launch_layer(game, layer, pos, rep);
        sfRenderWindow_display(game->window);
    }
}
