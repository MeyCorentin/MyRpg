/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create dialogues
*/

#include "../../includes/rpg.h"

void get_dialogues(game_ *game)
{
    int fd = open("dialogues.txt", O_RDONLY);
    int len = get_file_len("dialogues.txt");
    char *file = malloc(sizeof(char) * len + 1);

    if (fd == -1) {
        write(2, "invalid file\n", 13);
        exit(84);
    }
    read(fd, file, len);
    file[len] = '\0';
    game->dialogues->data_base = str_to_array(file, '\n');
}

void update_dialogue(game_ *game)
{
    if (game->dialogues->line == 0) {
        for (; my_strcmp(game->dialogues->data_base[game->dialogues->line],
        game->dialogues->quest) != 0; game->dialogues->line += 1);
    }
    sfText_setString(game->dialogues->text->text,
    insert_return(game->dialogues->data_base[game->dialogues->line + 1]));
    game->dialogues->name->rect.top = 1565 + 461 * game->dialogues->pnj;
    game->dialogues->speaker->rect.top = 1515 + 461 * game->dialogues->pnj;
    sfSprite_setTextureRect(game->dialogues->name->sprite,
    game->dialogues->name->rect);
    sfSprite_setTextureRect(game->dialogues->speaker->sprite,
    game->dialogues->speaker->rect);
}

void draw_dialogues(game_ *game)
{
    update_dialogue(game);
    sfRenderWindow_drawSprite(game->window, game->dialogues->box->sprite,
    sfFalse);
    sfRenderWindow_drawText(game->window, game->dialogues->text->text,
    sfFalse);
    sfRenderWindow_drawSprite(game->window, game->dialogues->name->sprite,
    sfFalse);
    sfRenderWindow_drawSprite(game->window, game->dialogues->speaker->sprite,
    sfFalse);
}

void create_dialogues(game_ *game)
{
    game->dialogues = malloc(sizeof(dialogues_));
    game->boole->on_dialogue = 1;
    game->dialogues->pnj = 0;
    game->dialogues->line = 0;
    game->dialogues->quest = "#CODE\n";
    get_dialogues(game);
    game->dialogues->box = create_button((sfVector2f){330, 605},
    (sfVector2f){1.5, 1.5}, "pictures/menu/dialogues.png");
    game->dialogues->name = create_button((sfVector2f){1120, 910},
    (sfVector2f){4, 4}, "pictures/env/all_mob.png");
    game->dialogues->name->rect = change_rect
    (game->dialogues->name->rect, 105, 25);
    sfSprite_setTextureRect(game->dialogues->name->sprite,
    game->dialogues->name->rect);
    game->dialogues->speaker = create_button((sfVector2f){1180, 640},
    (sfVector2f){4, 4}, "pictures/env/all_mob.png");
    game->dialogues->speaker->rect = change_rect
    (game->dialogues->speaker->rect, 75, 75);
    game->dialogues->speaker->rect.left = 183;
    sfSprite_setTextureRect(game->dialogues->speaker->sprite,
    game->dialogues->speaker->rect);
    game->dialogues->text = create_text(game->dialogues->data_base[1],
    (sfVector2f){2, 2}, (sfVector2f){400, 630}, "font/Stardew_Valley.ttf");
}

void dialogues_event(game_ *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyK)) {
        game->boole->on_dialogue = 0;
    }
    if (game->mouse.x > 1040 && game->mouse.x < 1060 && game->mouse.y > 980 &&
    game->mouse.y < 1005 && game->event.type == sfEvtMouseButtonReleased) {
        if (game->dialogues->data_base[game->dialogues->line + 2][0] == '#') {
            game->boole->on_dialogue = 1;
            game->dialogues->line = 0;
        } else
            game->dialogues->line += 1;
    }
}
