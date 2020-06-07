/*
** EPITECH PROJECT, 2020
** n4s
** File description:
** a lot of cmds-desu
*/

#include "my.h"

all *cmds_exec(all *info, char *cmd)
{
    int try = 0;
    int len = my_strlen(cmd);

    write(1, cmd, len);
    info = input_handler(info);
    if (info == NULL || good_returned(info->tab, 0) != 0) {
        if (try == 10)
            return NULL;
        try++;
        write(1, cmd, len);
        info = input_handler(info);
    }
    return info;
}