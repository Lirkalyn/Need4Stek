/*
** EPITECH PROJECT, 2020
** n4s
** File description:
** a lot of cmds-desu
*/

#include "my.h"

all *forward(all *info, char *cmd)
{
    int try = 0;

    fprintf(stderr, "f1\n");

    write(1, cmd, 16);
    read(0, info->buff, 256);
    info->tab = str_to_word_ar(info->buff, ':');
    if (good_returned(info->tab, 0) != 0) {
        fprintf(stderr, "f2\n");
        if (try == 10)
            return NULL;
        try++;
        write(1, cmd, 16);
        read(0, info->buff, 256);
        info->tab = str_to_word_ar(info->buff, ':');
    }
    return info;
}

all *left(all *info, char *cmd)
{
    int try = 0;
    int len = my_strlen(cmd);

    fprintf(stderr, "l1\n");

    write(1, cmd, len);
    read(0, info->buff, 256);
    info->tab = str_to_word_ar(info->buff, ':');
    if (good_returned(info->tab, 0) != 0) {
        fprintf(stderr, "l2\n");
        if (try == 10)
            return NULL;
        try++;
        write(1, cmd, len);
        read(0, info->buff, 256);
        info->tab = str_to_word_ar(info->buff, ':');
    }
    return info;
}

all *right(all *info, char *cmd)
{
    int try = 0;
    int len = my_strlen(cmd);

    fprintf(stderr, "r1\n");

    write(1, cmd, len);
    read(0, info->buff, 256);
    info->tab = str_to_word_ar(info->buff, ':');
    if (good_returned(info->tab, 0) != 0) {
        fprintf(stderr, "r2\n");
        if (try == 10)
            return NULL;
        try++;
        write(1, cmd, len);
        read(0, info->buff, 256);
        info->tab = str_to_word_ar(info->buff, ':');
    }
    return info;
}