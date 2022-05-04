/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-nathan.donat-filliod
** File description:
** detect_fight
*/

#include "../../includes/rpg.h"

void quests_abigail(quests_ *quest, game_ *game)
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
