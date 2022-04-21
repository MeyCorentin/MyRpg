/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** move_page_best
*/

#include "../../includes/rpg.h"

int move_page_best_left(game_ *game)
{
    if (game->mouse.x > 670 && game->mouse.x < 670 + 22
        && game->mouse.y > 560 && game->mouse.y < 560 + 22) {
        if (game->event.type == sfEvtMouseButtonReleased) {
            game->event.type = sfEvtCount;
            (game->best->page >= 2) ? (game->best->page -= 2) : 1;
            update_bestiary(game);
            game->boole->on_best = 1;
            open_close_best(game);
            game->boole->on_best = 0;
            open_close_best(game);
        }
    }
    return (0);
}

int move_page_best_right(game_ *game)
{
    if (game->mouse.x > 1240 && game->mouse.x < 1240 + 22
        && game->mouse.y > 560 && game->mouse.y < 560 + 22) {
        if (game->event.type == sfEvtMouseButtonReleased) {
            game->event.type = sfEvtCount;
            (game->best->page <= 5) ? (game->best->page += 2) : 1;
            update_bestiary(game);
            game->boole->on_best = 1;
            open_close_best(game);
            game->boole->on_best = 0;
            open_close_best(game);
        }
    }
    return (0);
}
