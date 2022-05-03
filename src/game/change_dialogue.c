/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** It's the file that contain functions to create dialogues
*/

#include "../../includes/rpg.h"

char *insert_return2(char *line)
{
    for (int cmpt = 0; line[cmpt] != '\0'; cmpt += 1) {
        if (line[cmpt] == '=')
            line[cmpt] = '\n';
    }
    return (line);
}

char *insert_return(char *line)
{
    int len =  my_strlen(line);
    int add = 0;
    int cmpt;
    int back;
    int pos = 0;
    char *new_line = malloc(sizeof(char) * (len + 1));

    if (len >= 27) {
        for (cmpt = 0; line[cmpt - add] != '\0'; cmpt += 1, pos += 1) {
            if (pos == 27) {
                pos = 0;
                for (back = cmpt - add; line[back] != ' '; back -= 1);
                new_line[back] = '\n';
                add += 1;
            } else
                new_line[cmpt - add] = line[cmpt - add];
        }
        new_line[cmpt - add] = '\0';
    } else
        return (line);
    return (new_line);
}