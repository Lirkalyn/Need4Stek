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