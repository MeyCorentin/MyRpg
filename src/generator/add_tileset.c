/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** add_tileset
*/

#include "../../includes/rpg.h"

int add_tileset(sfSprite ***map, sprite_ *sprite, char ***id_background)
{
    int i = 0;

    for (; map[i]; i++)
        add_copy_sprite(map, id_background, i, sprite);
    if (sprite->next != NULL)
        add_tileset(map, sprite->next, id_background);
    return (0);
}

int add_tileset_2(sfSprite ***map, sprite_ *sprite, char ***id_background)
{
    int i = 0;

    for (; map[i]; i++)
        add_copy_sprite(map, id_background, i, sprite);
    if (sprite->next != NULL)
        add_tileset(map, sprite->next, id_background);
    return (0);
}

int add_tileset_3(sfSprite ***map, sprite_ *sprite, char ***id_background)
{
    int i = 0;

    for (; map[i]; i++)
        add_copy_sprite(map, id_background, i, sprite);
    if (sprite->next != NULL)
        add_tileset(map, sprite->next, id_background);
    return (0);
}
