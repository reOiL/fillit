/***************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_tet_coordinate.c                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbernard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/03 15:30:03 by lbernard          #+#    #+#              #
#    Updated: 2019/10/03 15:30:03 by lbernard         ###   ########.fr        #
#                                                                              #
# *****************************************************************************/

#include "fillit.h"

int     *ft_tet_coordinate(char **list)
{
    int     i;
    int     j;
    int     *coord;
    int     p;

    i = 0;
    p = 0;
    coord = ft_memalloc(4);
    while (i < 4)
    {
        j = 0;
        while(j < 4 && p < 4)
        {
            if (list[i][j] != '.')
            {
                coord[p] = i * 10 + j;
                p++;
            }
            j++;
        }
        i++;
    }
    return (coord);
}
