/*
** EPITECH PROJECT, 2021
** EVAL_EXPR
** File description:
** It's a program that take a string an return the result as an integer
*/

#include "my.h"
#include <stdlib.h>

char *calculs_str(int count, int nb, char *resultat, int cmpt_str)
{
    int result;

    while (count >= 0) {
        count = count - 1;
        result = nb / puissance(count);
        result = result % 10;
        resultat[cmpt_str] = result + 48;
        cmpt_str += 1;
    }
    return (resultat);
}

int puissance(int y)
{
    int compteur = 0;
    int resultat = 1;

    while (compteur <= y) {
        resultat = resultat * 10;
        compteur = compteur + 1;
    }
    return resultat;
}

int get_len_nb(int nb)
{
    int len = 0;

    if (nb < 0)
        nb *= -1;
    while (nb >= 1) {
        nb /= 10;
        len += 1;
    }
    return (len);
}

char *new_put_nbr(int nb)
{
    int len = get_len_nb(nb);
    int count = -1;
    int digits = nb;
    int cmpt_str = 0;
    int is_neg = 1;
    char *resultat = malloc(sizeof(char) * (len + 1));

    if (nb < 0) {
        resultat[0] = '-';
        nb *= -1;
        digits *= -1;
        cmpt_str = 1;
        is_neg = 0;
    }
    if (nb == 0)
        return ("0");
    while (digits != 0) {
        digits = digits / 10;
        count = count + 1;
    }
    resultat = calculs_str(count, nb, resultat, cmpt_str);
    if (is_neg == 0)
        resultat[len + 1] = '\0';
    else
        resultat[len] = '\0';
    return (resultat);
}
