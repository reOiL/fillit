//
// Created by reoil on 14.10.2019.
//


#include "fillit.h"

void ft_error(int close) {
    ft_putendl_fd("error", 1);
    if (close)
        exit(0);
}