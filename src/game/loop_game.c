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
        event_cursor(game);
    }
}

char ***my_malloc_map(int colum, int lines)
{
    char ***temp = malloc(sizeof(char *) * (colum + 1));
    int k = 0;
    int j = 0;

    for (; k != colum; k++) {
        temp[k] = malloc(sizeof(char *) * lines + 1);
        for (j = 0; j != lines; j++) {
            temp[k][j] = malloc(sizeof(sfRectangleShape *));
        }
        temp[k][j] = '\0';
    }
    temp[k] = '\0';
    return (temp);
}

void init_map_square(char ***map, int y, int x)
{
    sfVector2f size = {40, 40};
    sfVector2f pos = {40 * y, 40 * x};
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos);
    map[y][x] = (char *)rect;
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

void display_load_map(char ***map, game_ *game)
{
    int y = 0;
    int x = 0;
    for (y = 0; map[y]; y++) {
        for (x = 0; map[y][x]; x++) {
            sfRenderWindow_drawRectangleShape(game->window,
            (sfRectangleShape *)map[y][x], sfFalse);
        }
    }
}

void launch_game(game_ *game)
{
    sfColor grey = {150, 150, 150, 150};
    load_map_ *load_map = malloc(sizeof(load_map_));
    get_size("background.txt", load_map);
    get_map(load_map);
    char ***map = my_malloc_map(load_map->y_size, load_map->x_size);
    init_map(map, load_map);
    while (sfRenderWindow_isOpen(game->window)) {
        game->on_button = 1;
        sfRenderWindow_clear(game->window, grey);
        display_load_map(map, game);
        check_event_game(game);
        update_cursor(game);
        sfRenderWindow_display(game->window);
    }
}
