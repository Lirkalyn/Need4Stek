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
        return forward(info, "CAR_FORWARD:1.0\n"); // 1.0
    if (mid_dist >= 1500)
        return forward(info, "CAR_FORWARD:0.7\n"); // 0.8
    if (mid_dist >= 1000)
        return forward(info, "CAR_FORWARD:0.4\n"); // 0.5
    if (mid_dist >= 600)
        return forward(info, "CAR_FORWARD:0.3\n"); // 0.4
    if (mid_dist >= 400)
        return forward(info, "CAR_FORWARD:0.2\n"); // 0.2
    else
        return forward(info, "CAR_FORWARD:0.1\n"); // 0.1
}

all *get_lidar(all *info)
{
    write(1, "GET_INFO_LIDAR\n", 15);
    read(0, info->buff, 256);
    info->tab = my_str_to_word_array(info->buff);
    if (good_returned(info->tab, 0) != 0)
        return NULL;
    info->dist = dist_mallocer(info->tab);
    info->dist = dist_giver(info->tab, info->dist);
    return info;
}

int ai(all *info)
{
    while (1) {
        info = get_lidar(info);
        info = select_speed(info, info->dist[15]); // info = select_speed(info, info->dist[(info->dist[0] / 2)]); // êut être faire la moyenne entre 15 et 16 ?
        if (info == NULL)
            return 84;
        info = get_lidar(info);
        info = right_or_left(info);
        if (info == NULL)
            return 84;
    }
}