//
// Created by reoil on 14.10.2019.
//

#include "fillit.h"

void    ft_swap(char *a, char *b)
{
    char c;

    c = *a;
    *a = *b;
    *b = c;
}

void    ft_swap_ptr(void **a, void **b)
{
    void *c;

    c = *a;
    *a = *b;
    *b = c;
}