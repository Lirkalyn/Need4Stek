/*
** EPITECH PROJECT, 2020
** n4s
** File description:
** for the dist-desu
*/

#include "my.h"

int isturn(int nb1, int nb2)
{
    int max = (nb1 > nb2) ? nb1 : nb2;
    int which = (nb1 > nb2) ? 0 : 1;
    int amax10 = max/10;

    if (which == 0 && ((nb1 - nb2) > amax10))
        return 1;
    else if (which == 1 && ((nb2 - nb1) > amax10))
        return 2;
    else
        return 0;
}

int *dist_mallocer_2(int *rsl, int len)
{
    int i = 0;

    rsl = malloc((len + 1) * sizeof(int));
    if (rsl == NULL)
        return NULL;
    for (; i < len; i++)
        rsl[i] = 0;
    rsl[0] = len;
    rsl[len] = -5;
    return rsl;
}

int *dist_mallocer(char **str)
{
    int i = 0;
    int j = 0;
    int len = 0;
    int good = 0;
    int goodd = 0;
    int *rsl = NULL;

    for (i = 0; str[i] != NULL; i++) {
        for (j = 0, good = 0, goodd = 0; str[i][j] != '\0'; j++) {
            if ((str[i][j] < '0' || str[i][j] > '9') && str[i][j] != '.')
                good = 1;
            if (str[i][j] == '.')
                goodd = 1;
        }
        if (good == 0 && goodd == 1)
            len++;
    }
    //fprintf(stderr, "%d\n\n", (len + 1));
    return dist_mallocer_2(rsl, (len + 1));
}

int *dist_giver_2(char *str, int *dist, int pos)
{
    int i = 0;

    for (; str[i] != '\0' && str[i] != '.'; i++) {
        dist[pos] *= 10;
        dist[pos] += (str[i] - '0');
    }
    return dist;
}

int *dist_giver(char **str, int *dist)
{
    int i = 0;
    int j = 0;
    int pos = 1;
    int good = 0;
    int goodd = 0;

    for (i = 0; str[i] != NULL; i++) {
        for (j = 0, good = 0, goodd = 0; str[i][j] != '\0'; j++) {
            if ((str[i][j] < '0' || str[i][j] > '9') && str[i][j] != '.')
                good = 1;
            if (str[i][j] == '.')
                goodd = 1;
        }
        if (good == 0 && goodd == 1) {
            dist = dist_giver_2(str[i], dist, pos);
            pos++;
        }
    }
    return dist;
}