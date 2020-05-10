/*
** EPITECH PROJECT, 2019
** str_compare.c
** File description:
** str_compare.c
*/

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

int str_n_compare(char *str, char *compare, int nb)
{
    int size1 = 0;
    int i = 0;

    for (; str[size1] != '\0'; size1++);
    for (i = 0; str[i] == compare[i] && i < nb; i++);
    if (i == nb)
        return (0);
    return (-1);
}

int str_compare(char *str, char *compare)
{
    int size1 = 0;
    int size2 = 0;
    int i = 0;

    for (; str[size1] != '\0'; size1++);
    for (; compare[size2] != '\0'; size2++);
    if (size1 == size2) {
        for (i = 0; str[i] == compare[i] && str[i] != '\0'
                    && compare[i] != '\0'; i++);
        if (i == size1)
            return (0);
    }
    return (-1);
}
