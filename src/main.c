/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "my.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

void my_put_str(char *str)
{
    write(2, str, my_strlen(str));
}

int main(void)
{
    char buff[246];
    char **info;

    write(1, "START_SIMULATION\n", 17);
    read(0, buff, 100);
    write(1, "CAR_FORWARD:0.5\n", 16);
    read(0, buff, 100);
    write(1, "GET_INFO_LIDAR\n", 15);
    read(0, buff, 246);
    info = str_to_word_ar(buff, ':');
    /*for (int i = 0; info[i] != NULL; i++) {
        my_put_str(info[i]);
        write(2, "\n", 1);
    }*/
    write(1, "STOP_SIMULATION\n", 16);
    read(0, buff, 100);
    write(2, buff, 30);
    write(2, "\n", 1);
    return (0);
}
