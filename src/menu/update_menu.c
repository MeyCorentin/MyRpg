/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function to update my menu
*/

#include "../../includes/rpg.h"

void find_button(game_ *game, int who)
{
    if (who == 1)
        launch_game(game);
    if (who == 2)
        launch_game(game);
    if (who == 3)
        sfRenderWindow_close(game->window);
}

void check_square(game_ *game, button_ *button, int who)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)game->window);

    if (mouse.x > button->position.x && mouse.x < button->position.x +
    button->rect.width * button->scale.x && mouse.y > button->position.y &&
    mouse.y < button->position.y + button->rect.height * button->scale.y) {
        button->rect.left = 372;
        if (game->event.type == sfEvtMouseButtonReleased)
            find_button(game, who);
    } else
        button->rect.left = 350;
    sfSprite_setTextureRect(button->sprite, button->rect);
}

void check_button(game_ *game, button_ *button, int who)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)game->window);

    if (mouse.x > button->position.x && mouse.x < button->position.x +
    button->rect.width * button->scale.x && mouse.y > button->position.y &&
    mouse.y < button->position.y + button->rect.height * button->scale.y) {
        button->rect.top = 245;
        if (game->event.type == sfEvtMouseButtonReleased)
            find_button(game, who);
    } else
        button->rect.top = 187;
    sfSprite_setTextureRect(button->sprite, button->rect);
}
