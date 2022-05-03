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
    write(fd, my_strncat(new_put_nbr(game->bonus->all), "\n", 0),
    my_strlen(new_put_nbr(game->bonus->all)) + 1);
    write(fd, my_strncat(new_put_nbr(game->bonus->attack), "\n", 0),
    my_strlen(new_put_nbr(game->bonus->attack)) + 1);
    write(fd, my_strncat(new_put_nbr(game->bonus->gold), "\n", 0),
    my_strlen(new_put_nbr(game->bonus->gold)) + 1);
    write(fd, my_strncat(new_put_nbr(game->bonus->life), "\n", 0),
    my_strlen(new_put_nbr(game->bonus->life)) + 1);
    write(fd, my_strncat(new_put_nbr(game->bonus->speed), "\n", 0),
    my_strlen(new_put_nbr(game->bonus->speed)) + 1);
}

void save_clock(game_ *game, int fd)
{
    write(fd, "#CLOCK\n", 7);
    write(fd, my_strncat(new_put_nbr(game->clock->hours), "\n", 0),
    my_strlen(new_put_nbr(game->clock->hours)) + 1);
    write(fd, my_strncat(new_put_nbr(game->clock->days), "\n", 0),
    my_strlen(new_put_nbr(game->clock->days)) + 1);
    write(fd, my_strncat(new_put_nbr(game->clock->saison), "\n", 0),
    my_strlen(new_put_nbr(game->clock->saison)) + 1);
    write(fd, "#END", 4);
}
