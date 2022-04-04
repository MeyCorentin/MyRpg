/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create my settings menu
*/

#include "../../includes/rpg.h"

void create_texts(menu_ *menu)
{
    menu->settings->all = malloc(sizeof(text_));
    menu->settings->all->text = sfText_create();
    menu->settings->all->position.x = menu->settings->back->position.x + 20;
    menu->settings->all->position.y = menu->settings->back->position.y + 20;
    menu->settings->all->scale = (sfVector2f){2, 2};
    menu->settings->all->font = sfFont_createFromFile
    ("font/Stardew_Valley.ttf");
    sfText_setFont(menu->settings->all->text, menu->settings->all->font);
    sfText_setPosition(menu->settings->all->text,
    menu->settings->all->position);
    sfText_setString(menu->settings->all->text,
    "FRAMERATE : \n\nSIZE : \n\nMUSIC : \n\nSOUNDS : \n");
    sfText_setColor(menu->settings->all->text, sfBlack);
    sfText_setScale(menu->settings->all->text, menu->settings->all->scale);
}
