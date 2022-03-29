/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** interact_grid
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../../includes/rpg.h"

void print_size(game_ *game, grid_cell_ *grid, FILE *file)
{
    fwrite(new_put_nbr(grid->size_y), 1,
    my_strlen(new_put_nbr(grid->size_y)), file);
    fwrite(" ", 1, my_strlen(" "), file);
    fwrite(new_put_nbr(grid->size_x), 1,
    my_strlen(new_put_nbr(grid->size_x)), file);
    fwrite("\n", 1, my_strlen("\n"), file);
}

void save_all(game_ *game, grid_cell_ *grid)
{
    FILE *foreground_file = fopen("foreground.txt", "wa");
    print_size(game, grid, foreground_file);
    save_foreground(game, grid, foreground_file);
    fclose(foreground_file);
    FILE *background_file = fopen("background.txt", "wa");
    print_size(game, grid, background_file);
    save_background(game, grid, background_file);
    fclose(background_file);
}

void moov_up_gen(sprite_ *sprite)
{
    sprite->position.y += 40;
    sfSprite_setPosition(sprite->sprite, sprite->position);
    if (sprite->next != NULL)
        moov_up_gen(sprite->next);
}

void moov_down_gen(sprite_ *sprite)
{
    sprite->position.y -= 40;
    sfSprite_setPosition(sprite->sprite, sprite->position);
    if (sprite->next != NULL)
        moov_down_gen(sprite->next);
}

void moov_right_gen(sprite_ *sprite)
{
    sprite->position.x += 40;
    sfSprite_setPosition(sprite->sprite, sprite->position);
    if (sprite->next != NULL)
        moov_right_gen(sprite->next);
}

void moov_left_gen(sprite_ *sprite)
{
    sprite->position.x -= 40;
    sfSprite_setPosition(sprite->sprite, sprite->position);
    if (sprite->next != NULL)
        moov_left_gen(sprite->next);
}

void page_handle(gen_control_ *gen_control)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum1)) {
        create_gen(gen_control, 1);
        gen_control->sprites_on = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum2)) {
        create_gen(gen_control, 2);
        gen_control->sprites_on = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum3)) {
        create_gen(gen_control, 3);
        gen_control->sprites_on = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum4)) {
        create_gen(gen_control, 4);
        gen_control->sprites_on = 0;
    }
}

void map_key_input(game_ *game, grid_cell_ *grid, gen_control_ *gen_control)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        (gen_control->sprites_on == 0) ? moov_up_gen(gen_control->list) :
        moov_up(grid);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        (gen_control->sprites_on == 0) ? moov_down_gen(gen_control->list) :
        moov_down(grid);
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        (gen_control->sprites_on == 0) ? moov_right_gen(gen_control->list) :
        moov_left(grid);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        (gen_control->sprites_on == 0) ? moov_left_gen(gen_control->list) :
        moov_right(grid);
    }
    (sfKeyboard_isKeyPressed(sfKeyR)) ? reset_grid(grid) : 1;
    (sfKeyboard_isKeyPressed(sfKeyEnter)) ? save_all(game, grid) : 1;
    page_handle(gen_control);
}

void map_mouse_input(game_ *game, grid_cell_ *grid,
paint_ *paint, gen_control_ *gen_control)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        left_click_grid(game, grid, paint, gen_control);
    if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
        right_click_grid(game, grid, paint, gen_control);
}
