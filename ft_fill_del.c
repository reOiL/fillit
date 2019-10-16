//
// Created by reoil on 14.10.2019.
//

#include "fillit.h"

void ft_fill_del(void *data, size_t size) {
    (void) size;
    ft_memdel(&data);
}