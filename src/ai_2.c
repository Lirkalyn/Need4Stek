/*
** EPITECH PROJECT, 2020
** n4s
** File description:
** moar ai-desu
*/

#include "my.h"

all *turn_left(all *info, int mid_dist)
{
    if (mid_dist <= 150)
        return cmds_exec(info, "WHEELS_DIR:0.0\n\0");
    if (mid_dist >= 1500)
        return cmds_exec(info, "WHEELS_DIR:-0.005\n\0");
    if (mid_dist >= 1300)
        return cmds_exec(info, "WHEELS_DIR:-0.01\n\0");
    if (mid_dist >= 1000)
        return cmds_exec(info, "WHEELS_DIR:-0.05\n\0");
    if (mid_dist >= 800)
        return cmds_exec(info, "WHEELS_DIR:-0.075\n\0");
    if (mid_dist >= 600)
        return cmds_exec(info, "WHEELS_DIR:-0.1\n\0");
    if (mid_dist >= 400)
        return cmds_exec(info, "WHEELS_DIR:-0.2\n\0");
    if (mid_dist >= 200)
        return cmds_exec(info, "WHEELS_DIR:-0.3\n\0");
    else
        return cmds_exec(info, "WHEELS_DIR:-0.5\n\0");
}

all *turn_right(all *info, int mid_dist)
{
    if (mid_dist <= 150)
        return cmds_exec(info, "WHEELS_DIR:0.0\n\0");
    if (mid_dist >= 1500)
        return cmds_exec(info, "WHEELS_DIR:0.005\n\0");
    if (mid_dist >= 1300)
        return cmds_exec(info, "WHEELS_DIR:0.01\n\0");
    if (mid_dist >= 1000)
        return cmds_exec(info, "WHEELS_DIR:0.05\n\0");
    if (mid_dist >= 800)
        return cmds_exec(info, "WHEELS_DIR:0.075\n\0");
    if (mid_dist >= 600)
        return cmds_exec(info, "WHEELS_DIR:0.1\n\0");
    if (mid_dist >= 400)
        return cmds_exec(info, "WHEELS_DIR:0.2\n\0");
    if (mid_dist >= 200)
        return cmds_exec(info, "WHEELS_DIR:0.3\n\0");
    else
        return cmds_exec(info, "WHEELS_DIR:0.5\n\0");
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