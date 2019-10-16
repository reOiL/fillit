//
// Created by reoil on 14.10.2019.
//

#include "fillit.h"

t_quad ft_tet_coordinate(char **list) {
    int i;
    int j;
    t_pair *ptr;
    int p;
    t_quad ret;

    i = 0;
    p = 0;
    ptr = &ret.p1;
    while (i < 4) {
        j = 0;
        while (j < 4 && p < 4) {
            if (list[i][j] != '.') {
                ptr->y = i;
                ptr->x = j;
                p++;
                ptr++;
            }
            j++;
        }
        i++;
    }
    return (ret);
}