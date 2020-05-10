/*
** EPITECH PROJECT, 2020
** n4s
** File description:
** a lot of cmds-desu
*/

#include "my.h"

int forward_full(void)
{
    char buff[256];
    char **info = NULL;
    int try = 0;

    write(1, "CAR_FORWARD:1.0\n", 16);
    read(0, buff, 256);
    info = str_to_word_ar(buff, ':');
    while (good_returned(info, 0) != 0) {
        if (try == 10)
            return 84;
        try++;
        write(1, "CAR_FORWARD:1.0\n", 16);
        read(0, buff, 256);
        info = str_to_word_ar(buff, ':');
    }
    return 0;
}

int forward_half(void)
{
    char buff[256];
    char **info = NULL;
    int try = 0;

    write(1, "CAR_FORWARD:0.5\n", 16);
    read(0, buff, 256);
    info = str_to_word_ar(buff, ':');
    while (good_returned(info, 0) != 0) {
        if (try == 10)
            return 84;
        try++;
        write(1, "CAR_FORWARD:0.5\n", 16);
        read(0, buff, 256);
        info = str_to_word_ar(buff, ':');
    }
    return 0;
}

int forward_half_half(void)
{
    char buff[256];
    char **info = NULL;
    int try = 0;

    write(1, "CAR_FORWARD:0.3\n", 16);
    read(0, buff, 256);
    info = str_to_word_ar(buff, ':');
    while (good_returned(info, 0) != 0) {
        if (try == 10)
            return 84;
        try++;
        write(1, "CAR_FORWARD:0.3\n", 16);
        read(0, buff, 256);
        info = str_to_word_ar(buff, ':');
    }
    return 0;
}

int forward_min(void)
{
    char buff[256];
    char **info = NULL;
    int try = 0;

    write(1, "CAR_FORWARD:0.1\n", 16);
    read(0, buff, 256);
    info = str_to_word_ar(buff, ':');
    while (good_returned(info, 0) != 0) {
        if (try == 10)
            return 84;
        try++;
        write(1, "CAR_FORWARD:0.1\n", 16);
        read(0, buff, 256);
        info = str_to_word_ar(buff, ':');
    }
    return 0;
}

int stop(void)
{
    char buff[256];
    char **info = NULL;
    int try = 0;

    write(1, "CAR_FORWARD:0.0\n", 16);
    read(0, buff, 256);
    info = str_to_word_ar(buff, ':');
    while (good_returned(info, 0) != 0) {
        if (try == 10)
            return 84;
        try++;
        write(1, "CAR_FORWARD:0.0\n", 16);
        read(0, buff, 256);
        info = str_to_word_ar(buff, ':');
    }
    return 0;
}