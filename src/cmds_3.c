/*
** EPITECH PROJECT, 2020
** n4s
** File description:
** -desu
*/

#include "my.h"

int left_1(void)
{
    char buff[256];
    char **info = NULL;
    int try = 0;

    if (forward_half() == 84)
        return 84;
    write(1, "WHEELS_DIR:-0.1\n", 15);
    read(0, buff, 256);
    info = str_to_word_ar(buff, ':');
    while (good_returned(info, 0) != 0) {
        if (try == 10)
            return 84;
        try++;
        write(1, "WHEELS_DIR:-0.1\n", 15);
        read(0, buff, 256);
        info = str_to_word_ar(buff, ':');
    }
    return 0;
}

int left_3(void)
{
    char buff[256];
    char **info = NULL;
    int try = 0;

    if (forward_half_half() == 84)
        return 84;
    write(1, "WHEELS_DIR:-0.3\n", 15);
    read(0, buff, 256);
    info = str_to_word_ar(buff, ':');
    while (good_returned(info, 0) != 0) {
        if (try == 10)
            return 84;
        try++;
        write(1, "WHEELS_DIR:-0.3\n", 15);
        read(0, buff, 256);
        info = str_to_word_ar(buff, ':');
    }
    return 0;
}

int left_5(void)
{
    char buff[256];
    char **info = NULL;
    int try = 0;

    if (forward_min() == 84)
        return 84;
    write(1, "WHEELS_DIR:-0.5\n", 15);
    read(0, buff, 256);
    info = str_to_word_ar(buff, ':');
    while (good_returned(info, 0) != 0) {
        if (try == 10)
            return 84;
        try++;
        write(1, "WHEELS_DIR:-0.5\n", 15);
        read(0, buff, 256);
        info = str_to_word_ar(buff, ':');
    }
    return 0;
}