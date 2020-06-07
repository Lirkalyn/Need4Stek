/*
** EPITECH PROJECT, 2020
** n4s
** File description:
** moar ai-desu
*/

#include "my.h"

all *turn_left(all *info, int mid_dist)
{
    if (mid_dist >= 1500)
        return left(info, "WHEELS_DIR:-0.005\n\0");
    if (mid_dist >= 1000)
        return left(info, "WHEELS_DIR:-0.05\n\0");
    if (mid_dist >= 600)
        return left(info, "WHEELS_DIR:-0.1\n\0");
    if (mid_dist >= 400)
        return left(info, "WHEELS_DIR:-0.2\n\0");
    if (mid_dist >= 200)
        return left(info, "WHEELS_DIR:-0.3\n\0");
    else
        return left(info, "WHEELS_DIR:-0.5\n\0");
}

all *turn_right(all *info, int mid_dist)
{
    if (mid_dist >= 1500)
        return right(info, "WHEELS_DIR:0.005\n\0");
    if (mid_dist >= 1000)
        return right(info, "WHEELS_DIR:0.05\n\0");
    if (mid_dist >= 600)
        return right(info, "WHEELS_DIR:0.1\n\0");
    if (mid_dist >= 400)
        return right(info, "WHEELS_DIR:0.2\n\0");
    if (mid_dist >= 200)
        return right(info, "WHEELS_DIR:0.3\n\0");
    else
        return right(info, "WHEELS_DIR:0.5\n\0");
}

all *right_or_left(all *info)
{
    int dir = (info->dist[1] - info->dist[32]);

    if (dir <= 0)
        return turn_left(info, info->dist[16]);
    else if (dir > 0)
        return turn_right(info, info->dist[16]);
    else
        return info;
}