/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** detect_fight
*/

#include "../../includes/rpg.h"

void active_quest(game_ *game, int id, quests_ *quest)
{
    if (quest->id_mob == id) {
        quest->state = 1;
        game->dialogues->quest = "#CODE\n";
        game->boole->on_dialogue = 0;
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
