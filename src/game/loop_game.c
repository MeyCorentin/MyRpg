/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void check_if_quit(game_ *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && game->boole->on_quit == 1
        && game->boole->on_inv == 1 && game->boole->on_girl == 1 &&
        game->boole->on_stats == 1 && game->boole->on_map == 1 &&
        game->boole->on_potion == 1 && game->boole->on_craft == 1 &&
        game->boole->on_pad == 1 && game->boole->on_quit == 1
        && game->clock->check_secs != 0) {
            game->boole->on_quit = 0;
            game->clock->check_secs = 0;
    }
}

void check_event_game(game_ *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        game->mouse = sfMouse_getPositionRenderWindow(game->window);
        if (game->event.type == sfEvtClosed) {
            sfMusic_stop(game->sounds->summer_day);
            sfRenderWindow_close(game->window);
        }
        check_if_quit(game);
        open_close_hint(game);
        event_cursor(game);
        move_select(game);
        check_event_items(game);
        open_close_inv(game);
        change_window(game);
        open_close_best(game);
        open_close_fight(game);
    }
}

void get_mob(char *files_name, game_ *game)
{
    int len = get_file_len(files_name);
    char *temp = malloc(sizeof(char) * len);
    int fd = open(files_name, O_RDONLY);

    read(fd, temp, len);
    temp[len - 1] = '\0';
    close(fd);
    game->best->mob_stats = my_split_tab(temp, '\n');
}

void set_game(game_ *game, char *pseudo)
{
    create_player(game, pseudo);
    create_bonus(game);
    game->player->movement = 4;
    game->first_item = NULL;
    sfMusic_stop(game->sounds->ocean);
    sfMusic_play(game->sounds->summer_day);
    create_inventory(game);
    create_ath(game);
    create_tree(game);
    create_life(game);
    create_bestiary(game);
    create_fight(game);
    get_mob("bestiary.txt", game);
    init_bestiary(game);
    set_boole(game);
}

void launch_game(game_ *game, char *pseudo)
{
    layer_ *layer = malloc(sizeof(layer_));
    gen_control_ *gen_control = malloc(sizeof(gen_control_));
    load_map_ *load_map = malloc(sizeof(load_map_));
    sfSprite *rep = sfSprite_create();
    game->layer_ = layer;
    init_layer(layer, load_map, gen_control, game);
    set_game(game, pseudo);
    add_items(game, game->first_item);
    add_items(game, game->first_item);
    game->first = create_enemy((sfVector2f){100, 100}, (sfIntRect){25, 480, 15, 30}, 90);
    get_last_enemy(game->first, (sfVector2f){300, 100}, (sfIntRect){25, 480, 15, 30}, 90);
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
