/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct All {
    char **tab;
    int *dist;
    int over;
} all;

int str_n_compare(char *str, char *compare, int nb);
char **str_to_word_ar(char *str, char chara);
void my_put_str(char *str);
int str_compare(char *str, char *compare);
void my_charerror(char e);
int my_put_nbr(int nb);
int my_puterror(char *str, int opt);
int *dist_mallocer(char **str);
int *dist_giver(char **str, int *dist);
int good_returned(char **str, int opt);
int ai(all *info);
all *forward(all *info, char *cmd);
all *left(all *info, char *cmd);
all *right(all *info, char *cmd);
all *right_or_left(all *info);
int my_strlen(char *str);
char **my_str_to_word_array(char const *str);
all *input_handler(all *info);
int is_over(all *info);

#endif
