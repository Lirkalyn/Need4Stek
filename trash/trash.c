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
        if (isturn(dist[1], dist[dist[0]]) == 1) {
            my_puterror("right", 0);
            check = ai_3(dist[0], dist, info);
        }
        else if (isturn(dist[1], dist[dist[0]]) == 2) {
            my_puterror("left", 0);
            check = ai_4(dist[0], dist, info);
        }
        else {
            my_puterror("front", 0);
            check = ai_2(dist[0], dist, info);
        }
        if (check != 0)
            return 84;
        //write(1, "STOP_SIMULATION\n", 16);
    }
    //return 1;
}

//    fprintf(stderr, "%s", info->buff);

//    for (int i = 0; info->tab[i] != NULL; i++)
//        fprintf(stderr, "%s\n", info->tab[i]);

//fprintf(stderr, "");

//    for (int i = 0; info->dist[i] != -5; i++)
//        fprintf(stderr, "%d\n", info->dist[i]);


        fprintf(stderr, "base\n\n");
        fprintf(stderr, "%s", info->buff);
        fprintf(stderr, "tab\n\n");
        for (int i = 0; info->tab[i] != NULL; i++)
            fprintf(stderr, "%s\n", info->tab[i]);
        fprintf(stderr, "nb\n\n");
        for (int i = 0; i < info->dist[0]; i++)
            fprintf(stderr, "%d\n", info->dist[i]);
        return 0;




int ai_4(int len, int *dist, char **info)
{
    int max = (dist[1] > dist[len]) ? dist[1] : dist[len];
    int which = (dist[1] > dist[len]) ? 0 : 1;
    int amax10 = max/10;
    int a3max10 = ((max/10) * 3);
    int a5max10 = ((max/10) * 5);

    if (which == 1 && ((dist[len] - dist[1]) > amax10)) {
        if ((dist[len] - dist[1]) > a5max10)
            return left_5();
        else if ((dist[len] - dist[1]) > a3max10)
            return left_3();
        else;
            return left_1();
    }
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
        if ((dist[1] - dist[len]) > a5max10)
            return right_5();
        else if ((dist[1] - dist[len]) > a3max10)
            return right_3();
        else;
            return right_1();
    return 0;
}

int ai_2(int len, int *dist, char **info)
{
    if (dist[(len / 2)] > 2750) {
        if (forward_full(0) == 84)
            return 84;
    }
    else if (dist[(len / 2)] > 1000) {
        if (forward_half(0) == 84)
            return 84;
    }
    else
        if (stop(0) == 84)
            return 84;
    return 0;
}



/*int main(void)
{
/*    char *line = NULL;
    int read = 0;
    size_t len = 0;


    all *info = info_initializer();
    //int error = 0;

//    if (info == NULL)
//        return 84;


    write(1, "START_SIMULATION\n", 17);
    info->read = getline(&info->buff, &info->size_buff, stdin);
    info->buff[(info->read - 1)] = '\0';
    fprintf(stderr, "%d = %s\n", info->read, info->buff);

/*    read = getline(&line, &len, stdin);
    fprintf(stderr, "%s", line);*/

/*    read(0, info->buff, 512);
    info->tab = my_str_to_word_array(info->buff);
    if (good_returned(info->tab, 0) != 0) {
        write(1, "STOP_SIMULATION\n", 16);
        return 84;
    }
    error = ai(info);
    if (error == 84) {
        write(1, "STOP_SIMULATION\n", 16);
        return 84;
    } else if (error == 0) {
        write(1, "STOP_SIMULATION\n", 16);
        return 0;
    }
}*/




/*
    fprintf(stderr, "pre-main\n");
    info->inp = inp_taker();
    fprintf(stderr, "post-main\n");
    while(info->inp->next != NULL) {
        fprintf(stderr, "ok\n");
        fprintf(stderr, "%s\n", info->inp->buff);
        info->inp = info->inp->next;
    }*/











/*all *input_handler(all *info)
{
    int i = 0;
    int read = 0;
    char *buff = NULL;
    size_t size_buff = 0;

    fprintf(stderr, "1\n");
    usleep(100);
    //info->read = 0;
    fprintf(stderr, "2\n");
//    free(info->buff);
    fprintf(stderr, "3\n");
//    info->buff = NULL;
    fprintf(stderr, "4\n");
//    info->size_buff = 0;
    fprintf(stderr, "5\n");
    read = getline(&buff, &size_buff, stdin);
    fprintf(stderr, "6\n");
    if (read != -1) {
        fprintf(stderr, "7\n");
        fprintf(stderr, "\n%s\n", buff);
        fprintf(stderr, "8\n");
        if ((read - 1) >= 0)
            buff[(read - 1)] = '\0';
//        fprintf(stderr, "9\n");
//        for (; info->tab != NULL && info->tab[i] != NULL; i++)
//            free(info->tab[i]);
        fprintf(stderr, "10\n");
        info->tab = my_str_to_word_array(buff);
        fprintf(stderr, "11\n");
        if (info->tab == NULL)
            return NULL;
        fprintf(stderr, "12\n");
    }
    fprintf(stderr, "13\n\n\n");
    return info;
}*/