/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function to check events sprites
*/

#include "../../includes/rpg.h"

void find_button_gen(game_ *game, int who, paint_ *paint)
{
    if (who == 1)
        paint->scale += 1;
    if (who == 2 && paint->scale > 1)
        paint->scale -= 1;
}

void check_gen(game_ *game, button_ *button, int who, paint_ *paint)
{
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)game->window);

    if (mouse.x > button->position.x && mouse.x < button->position.x +
    button->rect.width * button->scale.x && mouse.y > button->position.y &&
    mouse.y < button->position.y + button->rect.height * button->scale.y) {
        button->rect.left = 372;
        if (game->event.type == sfEvtMouseButtonReleased)
            find_button_gen(game, who, paint);
    } else
        button->rect.left = 350;
    sfSprite_setTextureRect(button->sprite, button->rect);
}

void interact_sprite(game_ *game, sprite_ *sprite, gen_control_ *gen_control)
{
    sfColor color = {255, 255, 255, 255};
    sfColor clear = {255, 255, 255, 150};
    sfVector2i mouse = sfMouse_getPosition((sfWindow *)game->window);

    if (mouse.x > sprite->position.x && mouse.x < sprite->position.x +
    sprite->rect.width * sprite->scale.x && mouse.y > sprite->position.y &&
    mouse.y < sprite->position.y + sprite->rect.height * sprite->scale.y) {
        sfSprite_setColor(sprite->sprite, color);
        if (game->event.type == sfEvtMouseButtonReleased &&
        gen_control->sprites_on == 0) {
            gen_control->selected_ = 1;
            gen_control->selected->id = sprite->id;
            sfSprite_setTextureRect(gen_control->selected->sprite,
            sprite->rect);
            gen_control->sprites_on = 1;
        }
    } else
        sfSprite_setColor(sprite->sprite, clear);
    if (sprite->next != NULL)
        interact_sprite(game, sprite->next, gen_control);
}

void check_event_gen(game_ *game, gen_control_ *gen_control, paint_ *paint)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (sfKeyboard_isKeyPressed(sfKeyEqual))
            paint->scale += 1;
        if (sfKeyboard_isKeyPressed(sfKeyHyphen) && paint->scale > 1)
            paint->scale -= 1;
        if (sfKeyboard_isKeyPressed(sfKeyO))
            gen_control->sprites_on = 0;
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            gen_control->sprites_on = 1;
        check_gen(game, gen_control->up, 1, paint);
        check_gen(game, gen_control->down, 2, paint);
        check_gen(game, gen_control->zoom_up, 3, paint);
        check_gen(game, gen_control->zoom_down, 4, paint);
    }
}

void draw_sprites_gen(game_ *game, gen_control_ *gen_control)
{
    if (gen_control->sprites_on == 0) {
        sfRenderWindow_clear(game->window, sfBlack);
        draw_env(game, gen_control->list);
    }
}
