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
    my_strlen(new_put_nbr(game->player->gold))+ 1);
    write(fd, my_strncat(game->pseudo, "\n", 0), my_strlen(game->pseudo) + 1);
    write(fd, my_strncat(new_put_nbr(game->player->stats->attack), "\n", 0),
    my_strlen(new_put_nbr(game->player->stats->attack)) + 1);
    write(fd, my_strncat(new_put_nbr(game->player->stats->life), "\n", 0),
    my_strlen(new_put_nbr(game->player->stats->life)) + 1);
    write(fd, my_strncat(new_put_nbr(game->player->stats->speed), "\n", 0),
    my_strlen(new_put_nbr(game->player->stats->speed)) + 1);
}

void save_inv(game_ *game, int fd)
{
    write(fd, "#INVENTORY\n", 11);
}

void save_map(game_ *game, int fd)
{
    sfVector2f pos_map = sfSprite_getPosition((sfSprite *)game->layer_->map_layer_1[0][0]);

    write(fd, "#MAP\n", 5);
    write(fd, my_strncat(new_put_nbr(pos_map.x), "\n", 0),
    my_strlen(new_put_nbr(pos_map.x)) + 1);
    write(fd, my_strncat(new_put_nbr(pos_map.y), "\n", 0),
    my_strlen(new_put_nbr(pos_map.y)) + 1);
}

int save_game(game_ *game)
{
    int fd = open("save.txt", O_WRONLY);
    if (fd == -1) {
        write(2, "invalid file\n", 13);
        return (84);
    }
    save_stats(game, fd);
    save_inv(game, fd);
    save_map(game, fd);
    save_skills(game, fd);
    save_clock(game, fd);
    close(fd);
    return (0);
}
