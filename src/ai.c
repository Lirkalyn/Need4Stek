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
        return forward(info, "CAR_FORWARD:0.9\n\0"); // 1.0
    if (mid_dist >= 1500)
        return forward(info, "CAR_FORWARD:0.7\n\0"); // 0.8
    if (mid_dist >= 1000)
        return forward(info, "CAR_FORWARD:0.4\n\0"); // 0.5
    if (mid_dist >= 600)
        return forward(info, "CAR_FORWARD:0.3\n\0"); // 0.4
    if (mid_dist >= 400)
        return forward(info, "CAR_FORWARD:0.2\n\0"); // 0.2
    else
        return forward(info, "CAR_FORWARD:0.1\n\0"); // 0.1
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
    if (info->over == 0)
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
        info = select_speed(info, info->dist[15]); // info = select_speed(info, info->dist[(info->dist[0] / 2)]); // peut être faire la moyenne entre 15 et 16 ?
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