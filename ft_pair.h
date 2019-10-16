//
// Created by reoil on 14.10.2019.
//

#ifndef FILLIT_FT_PAIR_H
#define FILLIT_FT_PAIR_H
typedef struct s_pair t_pair;

typedef struct s_quad t_quad;

struct s_pair {
    int x;
    int y;
};

struct s_quad {
    t_pair p1;
    t_pair p2;
    t_pair p3;
    t_pair p4;
};
#endif //FILLIT_FT_PAIR_H
