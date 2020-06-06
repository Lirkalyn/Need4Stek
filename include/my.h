/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#define EXIT_FAIL 84

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct All {
    size_t size_buff; // 0
    char *buff; // NULL
    int read; // 0
    char **tab; // NULL
    //int nb_dist; // 0
    int *dist; // NULL
    int over; // 0
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
//int forward_half(int opt);
//int stop(int opt);
int good_returned(char **str, int opt);
//int forward_full(int opt);
//int forward_half_half(int opt);
//int forward_min(int opt);
//int right_1(void);
//int right_3(void);
//int right_5(void);
int isturn(int nb1, int nb2);
//int left_1(void);
//int left_3(void);
//int left_5(void);
//int ai(void);
int ai(all *info);
//int whell_0(void);
all *forward(all *info, char *cmd);
all *left(all *info, char *cmd);
all *right(all *info, char *cmd);
all *right_or_left(all *info);
int my_strlen(char *str);
char **my_str_to_word_array(char const *str);

#endif
