/*
** EPITECH PROJECT, 2019
** str_to_word_ar.c
** File description:
** str_to_word_ar.c
*/

#include <stddef.h>
#include <stdlib.h>

int get_size_str(char *str, char chara, int i)
{
    int count = 1;

    for (; str[i] != chara && str[i] != '\n'; i++) {
        count++;
    }
    return (count);
}

char **str_to_word_ar(char *str, char chara)
{
    int count = 1;
    char **tab = NULL;

//    if (str == NULL)
//        return (NULL);
    for (int i = 0; str[i] != '\n'; i++)
        if (str[i] == chara && str[i + 1] != chara && str[i + 1] != '\n')
            count++;
    if ((tab = malloc(sizeof(char *) * (count + 1))) == NULL)
        return (NULL);
    tab[count] = NULL;
    for (int i = 0, y = 0; str[i] != '\n'; y++) {
        count = get_size_str(str, chara, i);
        tab[y] = malloc(sizeof(char) * (count + 1));
        for (int x = 0; str[i] != '\n' && str[i] != chara; i++, x++) {
            tab[y][x] = str[i];
            tab[y][count] = '\0';
        }
        for (; str[i] == chara && str[i] != '\n'; i++);}
    return (tab);
}
