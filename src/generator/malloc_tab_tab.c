/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain loop and events of my game
*/

#include "../../includes/rpg.h"

void init_map_square(char ***map, int y, int x)
{
    sfVector2f size = {40, 40};
    sfVector2f pos = {40 * x, 40 * y};
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos);
    map[y][x] = (char *)rect;
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

char ***my_malloc_map_sprite(int colum, int lines)
{
    char ***temp = malloc(sizeof(char *) * (colum + 1));
    int k = 0;
    int j = 0;

    for (; k != colum; k++) {
        temp[k] = malloc(sizeof(char *) * lines + 1);
        for (j = 0; j != lines; j++) {
            temp[k][j] = malloc(sizeof(sfSprite *));
        }
        temp[k][j] = '\0';
    }
    temp[k] = '\0';
    return (temp);
}

char ***my_malloc_big_tab(int colum, int lines)
{
    char ***temp = malloc(sizeof(char *) * (colum + 1));
    int k = 0;
    int j = 0;

    for (; k != colum; k++) {
        temp[k] = malloc(sizeof(char *) * lines + 1);
        for (j = 0; j != lines; j++) {
            temp[k][j] = malloc(sizeof(char *) * 100);
        }
        temp[k][j] = '\0';
    }
    temp[k] = '\0';
    return (temp);
}
