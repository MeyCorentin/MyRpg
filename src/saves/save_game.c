/*
** EPITECH PROJECT, 2021
** MY_RPG
** File description:
** It's the .h of my project my_rpg
*/

#include "../../includes/rpg.h"

void save_stats(game_ *game, int fd)
{
    write(fd, "#STATS\n", 8);
    write(fd, my_strncat(new_put_nbr(game->player->gold), "\n", 0),
    my_strlen(new_put_nbr(game->player->gold)) + 1);
    write(fd, my_strncat(game->pseudo, "\n", 0), my_strlen(game->pseudo) + 1);
    write(fd, my_strncat(new_put_nbr(game->player->stats->attack), "\n", 0),
    my_strlen(new_put_nbr(game->player->stats->attack)) + 1);
    write(fd, my_strncat(new_put_nbr(game->player->stats->life), "\n", 0),
    my_strlen(new_put_nbr(game->player->stats->life)) + 1);
    write(fd, my_strncat(new_put_nbr(game->player->stats->speed), "\n", 0),
    my_strlen(new_put_nbr(game->player->stats->speed)) + 1);
}

void save_inv(game_ *game, int fd, char ***inv)
{
    write(fd, "#INVENTORY\n", 11);
    for (int line = 0; inv[line]; line += 1) {
        for (int col = 0; inv[line][col]; col += 1) {
            my_printf("");
        }
    }
}

void save_map(game_ *game, int fd)
{
    write(fd, "#MAP\n", 5);
    write(fd, my_strncat(new_put_nbr(game->x_start), "\n", 0),
    my_strlen(new_put_nbr(game->x_start)) + 1);
    write(fd, my_strncat(new_put_nbr(game->y_start), "\n", 0),
    my_strlen(new_put_nbr(game->x_start)) + 1);
}

int save_game(game_ *game)
{
    int fd = open("save.txt", O_WRONLY);
    if (fd == -1) {
        write(2, "invalid file\n", 13);
        return (84);
    }
    save_stats(game, fd);
    save_inv(game, fd, game->inv->inv);
    save_map(game, fd);
    save_skills(game, fd);
    save_clock(game, fd);
    close(fd);
    return (0);
}
