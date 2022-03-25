/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function to update my menu
*/

#include "../../includes/rpg.h"

void move_parrot(animal_ *animal)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        animal->position.y -= 3;
        animal->version = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        animal->position.y += 3;
        animal->version = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        animal->position.x -= 3;
        animal->version = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        animal->position.x += 3;
        animal->version = 2;
    }
    sfSprite_setPosition(animal->sprite, animal->position);
}

void replace_parrot(animal_ *animal)
{
    if (animal->position.x < -24)
        animal->position.x = 1920;
    if (animal->position.x > 1920)
        animal->position.x = -24;
    if (animal->position.y < -24)
        animal->position.y = 1080;
    if (animal->position.y > 1080)
        animal->position.y = -24;
}

void update_animal(animal_ *animal, int x, int y)
{
    animal->time = sfClock_getElapsedTime(animal->clock);
    animal->secs = animal->time.microseconds / 5000;
    if (animal->secs > 30) {
        if (animal->rect.left < x + 48 + ((animal->version) * 72))
            animal->rect.left += 24;
        else
            animal->rect.left = x + (animal->version * 72);
        sfSprite_setTextureRect(animal->sprite, animal->rect);
        sfClock_restart(animal->clock);
    }
    if (animal->moved == 0)
        move_parrot(animal);
    else {
        animal->version = 0;
        animal->position.x -= 2;
        sfSprite_setPosition(animal->sprite, animal->position);
    }
    replace_parrot(animal);
}

void check_parrot(game_ *game, menu_ *menu)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)game->window);

    if (sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyS) ||
    sfKeyboard_isKeyPressed(sfKeyQ) || sfKeyboard_isKeyPressed(sfKeyD))
        menu->parrot->moved = 0;
    else
        menu->parrot->moved = 1;
    if (mouse.x > menu->parrot->position.x && mouse.x < menu->parrot->
    position.x + menu->parrot->rect.width * menu->parrot->scale.x && mouse.y
    > menu->parrot->position.y && mouse.y < menu->parrot->position.y + menu->
    parrot->rect.height * menu->parrot->scale.y)
        menu->on_parrot = 0;
    else
        menu->on_parrot = 1;
    sfSprite_setPosition(menu->parrot->sprite, menu->parrot->position);
}
