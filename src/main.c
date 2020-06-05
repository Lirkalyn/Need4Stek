/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "my.h"

int good_returned(char **str, int opt)
{
    int len = 0;
    while (str[len] != NULL)
        len++;
    if (len < 4)
        return 84;
    if (opt == 0)
        if (str_compare(str[1], "OK") != 0)
            return 84;
        else
            return 0;
}

all *info_initializer(void)
{
    all *info = malloc(sizeof(all));

    if (info == NULL)
        return NULL;
    //info->size_buff = 0;
    //info->buff = NULL;
    info->buff = malloc(256 * sizeof(char));
    if (info->buff == NULL)
        return NULL;
    info->tab = NULL;
    //info->nb_dist = 0;
    info->dist = NULL;
    info->over = 0;
    return info;
}

int main(void)
{
    all *info = info_initializer();

    if (info == NULL)
        return 84;
    write(1, "START_SIMULATION\n", 17);
    read(0, info->buff, 256);
    info->tab = str_to_word_ar(info->buff, ':');
    if (good_returned(info->tab, 0) != 0) {
        write(1, "STOP_SIMULATION\n", 16);
        return 84;
    }
    if (ai(info) == 84) {
        write(1, "STOP_SIMULATION\n", 16);
        return 84;
    }
    else if (ai(info) == 0) {
        write(1, "STOP_SIMULATION\n", 16);
        return 0;
    }
}
