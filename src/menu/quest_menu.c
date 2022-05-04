/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** detect_fight
*/

#include "../../includes/rpg.h"

void update_quests(game_ *game)
{
    if (game->boole->on_quests == 0) {
        sfRenderWindow_drawSprite(game->window, game->quests->back->sprite,
        sfFalse);
        draw_quests(game, game->quests);
    }
}

void quests_abigail(quests_ *quest, game_* game)
{
    my_printf("ABIGAIL\n");
    if (quest->stape == 1) {
        game->dialogues->quest = "#tuto_wood";
        add_items(game, game->first_item, 145);
    } if (quest->stape == 2) {
        game->dialogues->quest = "#tuto_ore";
        add_items(game, game->first_item, 145);
    } if (quest->stape == 3)
        game->dialogues->quest = "#tuto_monster";
    if (quest->stape == 4)
        game->dialogues->quest = "#tuto_end";
}

void quests_alex(quests_ *quest, game_ *game)
{
    my_printf("ALEX\n");
    if (quest->stape == 1)
        game->dialogues->quest = "#intro";
    if (quest->stape == 2)
        game->dialogues->quest = "#go_wood";
    if (quest->stape == 3)
        game->dialogues->quest = "#go_ore";
    if (quest->stape == 4)
        game->dialogues->quest = "#alex_end";
}

void quests_levis(quests_ *quest, game_ *game)
{
    my_printf("LEVIS\n");
    if (quest->stape == 1)
        game->dialogues->quest = "#levis_help";
    if (quest->stape == 2)
        game->dialogues->quest = "#levis_end";
}

void quests_clint(quests_ *quest, game_ *game)
{
    if (quest->stape == 1)
        game->dialogues->quest = "#clint_help";
    if (quest->stape == 2)
        game->dialogues->quest = "#clint_end";
}

void check_quest(game_ *game, int id, quests_ *quest)
{
    if (quest->id_mob == 10)
        quests_abigail(quest, game);
    if (quest->id_mob == 9)
        quests_alex(quest, game);
    if (quest->id_mob == 11)
        quests_levis(quest, game);
    if (quest->id_mob == 15)
        quests_clint(quest, game);
}

void active_quest(game_ *game, int id, quests_ *quest)
{
    if (quest->id_mob == id) {
        quest->state = 1;
        check_quest(game, id, quest);
        game->boole->on_dialogue = 0;
        game->dialogues->line = 0;
    } else if (quest->next != NULL)
        active_quest(game, id, quest->next);
}

void event_quests(game_ *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyC) && game->boole->on_quests == 1 &&
    game->clock->check_secs != 0) {
        game->boole->on_quests = 0;
        game->clock->check_secs = 0;
    } else if (sfKeyboard_isKeyPressed(sfKeyC) && game->boole->on_quests == 0
    && game->clock->check_secs != 0) {
        game->boole->on_quests = 1;
        game->clock->check_secs = 0;
    }
}
