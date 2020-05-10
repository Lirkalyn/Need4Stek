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

int main(void)
{
    char buff[256];
    char **info = NULL;
    int *dist = NULL;
    int over = 0;

    write(1, "START_SIMULATION\n", 17);
    read(0, buff, 256);
    info = str_to_word_ar(buff, ':');
    if (good_returned(info, 0) != 0) {
        write(1, "STOP_SIMULATION\n", 16);
        return 84;
    }
    while (over == 0)
        over = ai();
    write(1, "STOP_SIMULATION\n", 16);
}
