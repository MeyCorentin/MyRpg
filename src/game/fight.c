/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** fight
*/

#include "../../includes/rpg.h"

void create_fight(game_ *game)
{
    game->fight = malloc(sizeof(fight_));
    game->fight->enemy = malloc(sizeof(enemy_));
    game->fight->enemy = init_fight_mob(7);
    game->fight->leave = create_button((sfVector2f){380, 650},
    (sfVector2f){1, 1}, "pictures/menu/f_button.png");
    game->fight->attack = create_button((sfVector2f){780, 650},
    (sfVector2f){1, 1}, "pictures/menu/f_button.png");
    game->fight->heal = create_button((sfVector2f){1180, 650},
    (sfVector2f){1, 1}, "pictures/menu/f_button.png");
    game->fight->back = create_button((sfVector2f){300, 130},
    (sfVector2f){1, 1}, "pictures/menu/fight_back.png");
    game->fight->t_attack = create_text("ATTACK", (sfVector2f){3, 3},
    (sfVector2f){840, 660}, "font/Stardew_Valley.ttf");
    game->fight->t_heal = create_text("HEAL", (sfVector2f){3, 3},
    (sfVector2f){1270, 660}, "font/Stardew_Valley.ttf");
    game->fight->t_leave = create_text("RUN", (sfVector2f){3, 3},
    (sfVector2f){500, 660}, "font/Stardew_Valley.ttf");
    game->boole->on_fight = 1;
}

void update_button_leave(game_ *game)
{
    if (game->mouse.x > 360 && game->mouse.x < 360 + 383 &&
        game->mouse.y > 650 && game->mouse.y < 650 + 143 &&
        game->boole->on_fight == 0 &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
            game->boole->on_fight = 1;
            game->player->stats->life -= 1;
    }
}

void update_fight(game_ *game)
{
    game->clock->check_secs = game->clock->time.microseconds / 5000;
    if (game->boole->on_fight == 0) {
        update_button_leave(game);
        sfRenderWindow_drawSprite
        (game->window, game->fight->back->sprite, sfFalse);
        sfRenderWindow_drawSprite
        (game->window, game->fight->leave->sprite, sfFalse);
        sfRenderWindow_drawSprite
        (game->window, game->fight->attack->sprite, sfFalse);
        sfRenderWindow_drawSprite
        (game->window, game->fight->heal->sprite, sfFalse);
        sfRenderWindow_drawText(game->window, game->fight->t_attack->text,
        sfFalse);
        sfRenderWindow_drawText(game->window, game->fight->t_heal->text,
        sfFalse);
        sfRenderWindow_drawText(game->window, game->fight->t_leave->text,
        sfFalse);
        update_enemy_f(game->fight->enemy, game);
    }
}

void open_close_fight(game_ *game)
{
    if (game->boole->on_fight == 1 && sfKeyboard_isKeyPressed(sfKeyF) &&
    game->clock->check_secs != 0) {
        game->clock->check_secs = 0;
        game->boole->on_fight = 0;
        game->boole->on_inv = 1;
        game->boole->on_best = 1;
    } if (game->boole->on_fight == 0 && game->clock->check_secs != 0 &&
    (sfKeyboard_isKeyPressed(sfKeyF) || sfKeyboard_isKeyPressed(sfKeyEscape))
    && game->clock->check_secs != 0) {
        game->clock->check_secs = 0;
        game->boole->on_fight = 1;
    }
}
