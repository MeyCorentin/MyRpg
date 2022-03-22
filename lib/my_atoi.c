/*
** EPITECH PROJECT, 2022
** MY_ATOI
** File description:
** Transform string into int
*/

int my_atoi(char *str)
{
    int number = 0;
    int cmpt = 0;

    if (str[0] == '-')
        cmpt = 1;
    for (; str[cmpt] != '\0'; cmpt += 1) {
        number *= 10;
        number += (str[cmpt] - 48);
    }
    if (str[0] == '-')
        number *= -1;
    return (number);
}
