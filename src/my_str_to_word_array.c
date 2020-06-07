/*
** EPITECH PROJECT, 2019
** Day_08
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "my.h"

int calcsize(char const *str)
{
    int i;
    int size = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] < '0' || str[i] > '9')
            && (str[i] < 'A' || str[i] > 'Z')
            && (str[i] < 'a' || str[i] > 'z')
            && (str[i] == ':')) {
                size++;
        }
    }
    size++;
    return (size);
}

int count_memory(int i, char const *str, int size)
{
    while ((str[i] >= '0' && str[i] <= '9')
            || (str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= 'a' && str[i] <= 'z')
            || (str[i] == ' ')
            || (str[i] == '.')
            || (str[i] == '[')
            || (str[i] == ']')) {
        size++;
        i++;
    }
    return size;
}

void put_in_place(int *size, char **dest, int *progress, char const *str)
{
    int i;
    int j;

    for (i = 0; str[i] != '\0'; i++) {
        *size = count_memory(i, str, *size);
        i += *size;
        if (*size > 0) {
            dest[*progress] = malloc((*size + 1) * sizeof(char));
            for (j = 0; j < *size; j++)
                dest[*progress][j] = str[((i - *size) + j)];
            dest[*progress][j] = '\0';
            *progress += 1;
            *size = 0;
            i--;
        }
    }
}

char **my_str_to_word_array(char const *str)
{
    int progress = 0;
    int size = 0;
    char **dest;

    if (str == NULL)
        return NULL;
    fprintf(stderr, "\n%s\n", str);
    size = calcsize(str);
    fprintf(stderr, "size = %d\n", size);
    dest = malloc((size + 1) * sizeof(char *));
    if (dest == NULL)
        return NULL;
    dest[size] = NULL;
    size = 0;
    put_in_place(&size, dest, &progress, str);
    for (int i = 0; dest[i] != NULL; i++)
        fprintf(stderr, "->%s\n", dest[i]);
    fprintf(stderr, "\n\n");
    return dest;
}