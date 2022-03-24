/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function to update my menu
*/

#include "../../includes/rpg.h"

void update_animal(animal_ *animal, int x, int y)
{
    animal->time = sfClock_getElapsedTime(animal->clock);
    animal->secs = animal->time.microseconds / 5000;
    if (animal->secs > 30) {
        if (animal->rect.left < 86)
            animal->rect.left += 24;
        else
            animal->rect.left = x;
        sfSprite_setTextureRect(animal->sprite, animal->rect);
        sfClock_restart(animal->clock);
    }
    animal->position.x -= 1;
    sfSprite_setPosition(animal->sprite, animal->position);
    if (animal->position.x < -24) {
        animal->position.x = 1920;
        animal->position.y = rand() % 1050;
    }
}

void find_button(game_ *game, int who)
{
    if (who == 1)
        launch_game(game);
    if (who == 2)
        launch_game(game);
    if (who == 3)
        sfRenderWindow_close(game->window);
}

void check_parrot(game_ *game, menu_ *menu)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)game->window);

    if (mouse.x > menu->parrot->position.x && mouse.x < menu->parrot->\
    position.x + menu->parrot->rect.width * menu->parrot->scale.x && mouse.y \
    > menu->parrot->position.y && mouse.y < menu->parrot->position.y + menu->\
    parrot->rect.height * menu->parrot->scale.y)
        menu->on_parrot = 0;
    else
        menu->on_parrot = 1;
}

void check_square(game_ *game, button_ *button, int who)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)game->window);

    if (mouse.x > button->position.x && mouse.x < button->position.x + \
    button->rect.width * button->scale.x && mouse.y > button->position.y && \
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

    if (mouse.x > button->position.x && mouse.x < button->position.x + \
    button->rect.width * button->scale.x && mouse.y > button->position.y && \
    mouse.y < button->position.y + button->rect.height * button->scale.y) {
        button->rect.top = 245;
        if (game->event.type == sfEvtMouseButtonReleased)
            find_button(game, who);
    } else
        button->rect.top = 187;
    sfSprite_setTextureRect(button->sprite, button->rect);
}
