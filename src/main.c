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
        if (str_compare(str[1], "OK\0") != 0)
            return 84;
        else
            return 0;
}

all *info_initializer(void)
{
    all *info = malloc(sizeof(all));

    if (info == NULL)
        return NULL;
    info->size_buff = 0;
    info->buff = NULL;
    info->read = 0;
    info->tab = NULL;
    info->dist = NULL;
    info->over = 0;
    return info;
}

int main(void)
{
    all *info = info_initializer();
    int error = 0;

    if (info == NULL)
        return 84;
    write(1, "START_SIMULATION\n", 17);
    info->read = getline(&info->buff, &info->size_buff, stdin);
    info->buff[(info->read - 1)] = '\0';
    info->tab = my_str_to_word_array(info->buff);
    if (good_returned(info->tab, 0) != 0) {
        write(1, "STOP_SIMULATION\n", 16);
        return 84;
    }
    error = ai(info);
    if (error == 84) {
        write(1, "STOP_SIMULATION\n", 16);
        return 84;
    } else if (error == 0) {
        write(1, "STOP_SIMULATION\n", 16);
        return 0;
    }
}