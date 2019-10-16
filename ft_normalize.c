//
// Created by reoil on 14.10.2019.
//

#include <assert.h>
#include "fillit.h"

int  ft_find_up(char **buff)
{
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (buff[i][j] != '.')
                return (i);
            j++;
        }
        i++;
    }
    return (-1);
}

int ft_find_right(char **buff)
{
    int i;
    int j;
    int f;

    f = 1000;
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (buff[j][i] != '.')
            {
                if (f > i)
                    f = i;
                break;
            }
            j++;
        }
        i++;
    }
    return (f == 1000 ? -1 : f);
}

char **ft_normalize(char **buff) {
    t_pair swap_pair;
    int i;
    int j;
    int d;

    if (!buff)
		return (NULL);
    swap_pair.x = ft_find_up(buff);
    assert(swap_pair.x != -1);
    swap_pair.y = ft_find_right(buff);
    assert(swap_pair.y != -1);
    i = 0;
    while (i < swap_pair.x)
    {
        j = 1;//TODO: fix me
        while (j < 4)
        {
            ft_swap_ptr((void **)&buff[i + j - 1], (void **)&buff[j]);
            j++;
        }
        i++;
    }
    d = 0;
    while (d < swap_pair.y)
    {
        i = 0;
        while (i < 4)
        {
            j = 1;
            while (j < 4)
            {
                ft_swap(&buff[i][j - 1], &buff[i][j]);
                j++;
            }
            i++;
        }
        d++;
    }
    return (buff);
}