/*
** EPITECH PROJECT, 2020
** n4s
** File description:
** ai-desu
*/

#include "my.h"

all *select_speed(all *info, int mid_dist)
{
    if (mid_dist >= 2000)
        return cmds_exec(info, "CAR_FORWARD:0.9\n\0");
    if (mid_dist >= 1500)
        return cmds_exec(info, "CAR_FORWARD:0.7\n\0");
    if (mid_dist >= 1000)
        return cmds_exec(info, "CAR_FORWARD:0.4\n\0");
    if (mid_dist >= 600)
        return cmds_exec(info, "CAR_FORWARD:0.3\n\0");
    if (mid_dist >= 400)
        return cmds_exec(info, "CAR_FORWARD:0.2\n\0");
    else
        return cmds_exec(info, "CAR_FORWARD:0.1\n\0");
}

int is_over(all *info)
{
    int len = 0;

    for (; info->tab[len] != NULL; len++);
    if (str_compare(info->tab[(len - 2)], "Track Cleared\0") == 0)
        return 0;
    return 1;
}

all *get_lidar(all *info)
{
    write(1, "GET_INFO_LIDAR\n", 15);
    info = input_handler(info);
    if (good_returned(info->tab, 0) != 0 || info == NULL)
        return NULL;
    if (info->dist != NULL) {
        free(info->dist);
        info->dist = NULL;
    }
    info->dist = dist_mallocer(info->tab);
    if (info == NULL)
        return NULL;
    info->dist = dist_giver(info->tab, info->dist);
    info->over = is_over(info);
    return info;
}

int ai_return_value(all *info)
{

    if (info == NULL)
        return 84;
    if (info->over == 0 || is_over(info) == 0)
        return 0;
    return -1;
}

int ai(all *info)
{
    int return_value = 0;

    while (1) {
        info = get_lidar(info);
        return_value = ai_return_value(info);
        if (return_value == 84 || return_value == 0)
            return return_value;
        info = select_speed(info, info->dist[16]);
        return_value = ai_return_value(info);
        if (return_value == 84 || return_value == 0)
            return return_value;
        info = get_lidar(info);
        return_value = ai_return_value(info);
        if (return_value == 84 || return_value == 0)
            return return_value;
        info = right_or_left(info);
        return_value = ai_return_value(info);
        if (return_value == 84 || return_value == 0)
            return return_value;
    }
}