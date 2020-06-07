/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "my.h"

int good_returned(char **str, int opt)
{
    int len = 0;

    while (str[len] != NULL)
        len++;
    if (len < 4)
        return 84;
    if (opt == 0)
        if (str_compare(str[1], "OK\0") != 0)
            return 84;
        else
            return 0;
}

all *info_initializer(void)
{
    all *info = malloc(sizeof(all));

    if (info == NULL)
        return NULL;
//    info->size_buff = 0;
//    info->buff = NULL;
//    info->read = 0;
    info->tab = NULL;
    info->dist = NULL;
    info->over = 1;
    return info;
}

char **tab_giver(void)
{
    int read = 0;
    char *buff = NULL;
    size_t size_buff = 0;
    char **rsl = NULL;

    //usleep(1000);
    read = getline(&buff, &size_buff, stdin);
    if (read != -1) {
//        fprintf(stderr, "7\n");
//        fprintf(stderr, "\n%s\n", buff);
//        fprintf(stderr, "8\n");
        if ((read - 1) >= 0)
            buff[(read - 1)] = '\0';
//        fprintf(stderr, "9\n");
//        for (; info->tab != NULL && info->tab[i] != NULL; i++)
//            free(info->tab[i]);
//        fprintf(stderr, "10\n");
        rsl = my_str_to_word_array(buff);
//        fprintf(stderr, "11\n");
        if (rsl == NULL)
            return NULL;
        else
            return rsl;
//        fprintf(stderr, "12\n");
    }
    else
        return rsl;
}

all *input_handler(all *info)
{
    int i = 0;

//    if (info->tab != NULL)
//        for (; info->tab[i] != NULL; i++)
//            free(info->tab[i]);
    info->tab = tab_giver();
    return info;
}

int main(void)
{
    all *info = info_initializer();
    int error = 0;

    if (info == NULL)
        return 84;
    write(1, "START_SIMULATION\n", 17);
    info = input_handler(info);
    if (good_returned(info->tab, 0) != 0) {
        write(1, "STOP_SIMULATION\n", 16);
        return 84;
    }
    error = ai(info);
    if (error == 84) {
        write(1, "STOP_SIMULATION\n", 16);
        fprintf(stderr, "ERROR!!!\n");
        return 84;
    }
    else if (error == 0) {
        write(1, "STOP_SIMULATION\n", 16);
        fprintf(stderr, "GG!!!\n");
        return 0;
    }
}