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

int str_n_compare(char *str, char *compare, int nb);
char **str_to_word_ar(char *str, char chara);
void my_put_str(char *str);
int str_compare(char *str, char *compare);
void my_charerror(char e);
int my_put_nbr(int nb);
int my_puterror(char *str, int opt);
int *dist_mallocer(char **str);
int *dist_giver(char **str, int *dist);
int forward_half(void);
int stop(void);
int good_returned(char **str, int opt);
int forward_full(void);
int forward_half_half(void);
int forward_min(void);
int right_1(void);
int right_3(void);
int right_5(void);
int isturn(int nb1, int nb2);
int left_1(void);
int left_3(void);
int left_5(void);
int ai(void);

#endif
