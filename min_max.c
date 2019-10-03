/***************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    min_max.c                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbernard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/03 15:30:03 by lbernard          #+#    #+#              #
#    Updated: 2019/10/03 15:30:03 by lbernard         ###   ########.fr        #
#                                                                              #
# *****************************************************************************/

#include "fillit.h"

int         *min_max(int *c)
{
    int     b;
    int     *minmax;
    int     k;

    k = 0;
    minmax = ft_memalloc(4);
    minmax[0] = c[k] / 10;
    minmax[1] = c[k] / 10;
    minmax[2] = c[k] % 10;
    minmax[3] = c[k] % 10;
    while(k < 4)
    {
        if (minmax[0] > c[k] / 10)
            minmax[0] = c[k] / 10;
        if (minmax[1] < c[k] / 10)
            minmax[1] = c[k] / 10;
        if (minmax[2] > c[k] % 10)
            minmax[2] = c[k] % 10;
        if (minmax[3] < c[k] % 10)
            minmax[3] = c[k] % 10;
        k++;
    }
    return (minmax);
}
