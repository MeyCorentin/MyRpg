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
