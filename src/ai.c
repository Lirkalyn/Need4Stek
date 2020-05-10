/*
** EPITECH PROJECT, 2020
** n4s
** File description:
** ai-desu
*/

#include "my.h"

int ai_4(int len, int *dist, char **info)
{
    int max = (dist[1] > dist[len]) ? dist[1] : dist[len];
    int which = (dist[1] > dist[len]) ? 0 : 1;
    int amax10 = max/10;
    int a3max10 = ((max/10) * 3);
    int a5max10 = ((max/10) * 5);

    if (which == 1 && ((dist[len] - dist[1]) > amax10))
        if ((dist[len] - dist[1]) > a5max10);
            if (left_5() == 84)
                return 84;
        else if ((dist[len] - dist[1]) > a3max10);
            if (left_3() == 84)
                return 84;
        else;
            if (left_1() == 84)
                return 84;
    return 0;
}

int ai_3(int len, int *dist, char **info)
{
    int max = (dist[1] > dist[len]) ? dist[1] : dist[len];
    int which = (dist[1] > dist[len]) ? 0 : 1;
    int amax10 = max/10;
    int a3max10 = ((max/10) * 3);
    int a5max10 = ((max/10) * 5);

    if (which == 0 && ((dist[1] - dist[len]) > amax10))
        if ((dist[1] - dist[len]) > a5max10);
            if (right_5() == 84)
                return 84;
        else if ((dist[1] - dist[len]) > a3max10);
            if (right_3() == 84)
                return 84;
        else;
            if (right_1() == 84)
                return 84;
    return 0;
}

int ai_2(int len, int *dist, char **info)
{
    if (dist[(len / 2)] > 2750) {
        if (forward_full() == 84)
            return 84;
    }
    else if (dist[(len / 2)] > 1000) {
        if (forward_half() == 84)
            return 84;
    }
    else
        if (stop() == 84)
            return 84;
    return 0;
}

int ai(void)
{
    char buff[256];
    char **info = NULL;
    int *dist = NULL;
    int check = 0;

    while (1) {
        write(1, "GET_INFO_LIDAR\n", 15);
        read(0, buff, 256);
        info = str_to_word_ar(buff, ':');
        if (good_returned(info, 0) != 0)
            return 84;
        dist = dist_mallocer(info);
        dist = dist_giver(info, dist);
        if (isturn(dist[1], dist[dist[0]]) == 1)
            check = ai_3(dist[0], dist, info);
        else if (isturn(dist[1], dist[dist[0]]) == 2)
            check = ai_4(dist[0], dist, info);
        else
            check = ai_2(dist[0], dist, info);
        if (check != 0)
            return 84;
        write(1, "STOP_SIMULATION\n", 16);
    }
    return 1;
}