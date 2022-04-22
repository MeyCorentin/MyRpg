/*
** EPITECH PROJECT, 2021
** MY_RPG
** File description:
** It's the .h of my project my_rpg
*/

#include "../../includes/rpg.h"

void save_skills(game_ *game, int fd)
{
    write(fd, "#SKILLS\n", 8);
    write(fd, my_strncat(new_put_nbr(game->bonus->attack), "\n", 0),
    my_strlen(new_put_nbr(game->bonus->attack)) + 2);
    write(fd, my_strncat(new_put_nbr(game->bonus->gold), "\n", 0),
    my_strlen(new_put_nbr(game->bonus->gold)) + 2);
    write(fd, my_strncat(new_put_nbr(game->bonus->life), "\n", 0),
    my_strlen(new_put_nbr(game->bonus->life)) + 2);
    write(fd, my_strncat(new_put_nbr(game->bonus->speed), "\n", 0),
    my_strlen(new_put_nbr(game->bonus->speed)) + 2);
}

void save_clock(game_ *game, int fd)
{
    write(fd, "#CLOCK\n", 7);
    write(fd, my_strncat(new_put_nbr(game->clock->hours), "\n", 0),
    my_strlen(new_put_nbr(game->clock->hours)) + 2);
    write(fd, my_strncat(new_put_nbr(game->clock->days), "\n", 0),
    my_strlen(new_put_nbr(game->clock->days)) + 2);
}
