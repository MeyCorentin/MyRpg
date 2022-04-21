/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** bestiary
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

void create_bestiary(game_ *game)
{
    game->best = malloc(sizeof(bestiary_));
    game->best->page = 1;
    game->best->back = create_button((sfVector2f){630, 230},
    (sfVector2f){1, 1}, "pictures/menu/book.png");
    game->best->arrow_l = create_button((sfVector2f){670, 560},
    (sfVector2f){1.5, 1.5}, "pictures/menu/arrow_l.png");
    game->best->arrow_r = create_button((sfVector2f){1240, 560},
    (sfVector2f){1.5, 1.5}, "pictures/menu/arrow_r.png");
    sfSprite_setScale(game->best->back->sprite, (sfVector2f){2, 2});
    game->boole->on_best = 1;
    game->best->page_l = create_text(new_put_nbr(game->best->page),
    (sfVector2f){1, 1}, (sfVector2f){800, 550}, "font/Stardew_Valley.ttf");
    game->best->page_r = create_text(new_put_nbr(game->best->page + 1),
    (sfVector2f){1, 1}, (sfVector2f){1120, 550}, "font/Stardew_Valley.ttf");
}

void update_bestiary(game_ *game)
{
    game->clock->check_secs = game->clock->time.microseconds / 5000;
    if (game->boole->on_best == 0) {
        sfText_setString(game->best->page_l->text,
        new_put_nbr(game->best->page));
        sfText_setString(game->best->page_r->text,
        new_put_nbr(game->best->page + 1));
        sfRenderWindow_drawSprite
        (game->window, game->best->back->sprite, sfFalse);
        sfRenderWindow_drawText(game->window, game->best->page_l->text,
        sfFalse);
        sfRenderWindow_drawText(game->window, game->best->page_r->text,
        sfFalse);
        sfRenderWindow_drawSprite
        (game->window, game->best->arrow_l->sprite, sfFalse);
        sfRenderWindow_drawSprite
        (game->window, game->best->arrow_r->sprite, sfFalse);
    }
}

void open_close_best(game_ *game)
{
    if (game->boole->on_best == 1 && sfKeyboard_isKeyPressed(sfKeyB) &&
    game->clock->check_secs != 0) {
        game->clock->check_secs = 0;
        game->boole->on_best = 0;
        game->boole->on_inv = 1;
    } if (game->boole->on_best == 0 && game->clock->check_secs != 0 &&
    (sfKeyboard_isKeyPressed(sfKeyB) || sfKeyboard_isKeyPressed(sfKeyEscape))
    && game->clock->check_secs != 0) {
        game->clock->check_secs = 0;
        game->boole->on_best = 1;
    }
}
