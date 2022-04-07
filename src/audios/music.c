/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain function to create my musics
*/

#include "../../includes/rpg.h"

sfSound *create_sound(char *filepath)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(filepath);
    sfSound_setBuffer(sound, buffer);
    return (sound);
}

sfMusic *create_music(char *filepath)
{
    sfMusic *music = sfMusic_createFromFile(filepath);
    sfMusic_setLoop(music, sfTrue);
    return (music);
}

void create_audios(game_ *game)
{
    game->sounds = malloc(sizeof(sounds_));
    game->sounds->click = create_sound("sounds/mouseClick.wav");
    game->sounds->coin = create_sound("sounds/Pickup_Coin15.wav");
    game->sounds->parrot = create_sound("sounds/parrot.wav");
    game->sounds->ocean = create_music("sounds/ocean.wav");
    game->sounds->summer_day = create_music("sounds/summer_day.wav");
}
