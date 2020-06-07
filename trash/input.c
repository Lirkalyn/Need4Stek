/*
** EPITECH PROJECT, 2020
** n4s
** File description:
** take the input (output) of the API and put it in a useable form-desu
*/

#include "my.h"

input_t *inp_rewinder(input_t *inp)
{
    fprintf(stderr, "test\n");
    while (inp->preview != NULL)
        inp = inp->preview;
    return inp;
}

input_t *inp_mallocer(void)
{
    input_t *inp = malloc(sizeof(input_t));

    if (inp == NULL)
        return NULL;
    inp->buff = NULL;
    inp->size_buff = 0;
    inp->read = 0;
    inp->next = NULL;
    inp->preview = NULL;
    fprintf(stderr, "mallocer\n");
    return inp;
}

input_t *inp_filler(input_t *inp, char *buf, ssize_t read)
{
    void *tmp;

    inp->buff = buf;
    inp->size_buff = read;
    tmp = inp;
    inp->next = inp_mallocer();
    if (inp->next == NULL)
        return NULL;
    inp = inp->next;
    inp->preview = tmp;
    fprintf(stderr, "filler\n");
    return inp;
}

input_t *inp_taker(void)
{
    input_t *inp = inp_mallocer();
    char *buf = NULL;
    size_t len = 0;
    ssize_t read = 0;

    if (inp == NULL)
        return NULL;
    while (1) {
//        info->read = getline(&info->buff, &info->size_buff, stdin);
        fprintf(stderr, "in\n");
        //read = getline(&buf, &len, stdin);
        read = fscanf(stdin, "%s", buf);
        fprintf(stderr, "read = %ld\n", read);
        if (read == 0)
            return inp_rewinder(inp);
        else {
            //buf[(read - 1)] = '\0';
            inp = inp_filler(inp, buf, read);
            buf = NULL;
            //read = 0;
            len = 0;
            fprintf(stderr, "aaaa\n");
        }
        fprintf(stderr, "strange\n");
    }
    fprintf(stderr, "out?\n");
}