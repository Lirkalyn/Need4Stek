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
    int len = my_strlen(cmd);

    write(1, cmd, len);
    info = input_handler(info);
    //info->over = is_over(info);
/*    if (info == NULL || good_returned(info->tab, 0) != 0) {
        if (try == 10)
            return NULL;
        try++;
        write(1, cmd, len);
        info = input_handler(info);
    }*/
    return info;
}

all *left(all *info, char *cmd)
{
    int try = 0;
    int len = my_strlen(cmd);

    write(1, cmd, len);
    info = input_handler(info);
    //info->over = is_over(info);
/*    if (info == NULL || good_returned(info->tab, 0) != 0) {
        if (try == 10)
            return NULL;
        try++;
        write(1, cmd, len);
        info = input_handler(info);
    }*/
    return info;
}

all *right(all *info, char *cmd)
{
    int try = 0;
    int len = my_strlen(cmd);

    write(1, cmd, len);
    info = input_handler(info);
    //info->over = is_over(info);
/*    if (info == NULL || good_returned(info->tab, 0) != 0) {
        if (try == 10)
            return NULL;
        try++;
        write(1, cmd, len);
        info = input_handler(info);
    }*/
    return info;
}