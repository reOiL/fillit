/***************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_tet_to_num.c                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbernard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/03 15:30:03 by lbernard          #+#    #+#              #
#    Updated: 2019/10/03 15:30:03 by lbernard         ###   ########.fr        #
#                                                                              #
# *****************************************************************************/

#include "fillit.h"

int    ft_tet_to_num(char **list)
{
    int                i;
    int                j;
    unsigned int    ret;

    i = 4;
    ret = 1;
    while (--i > -1)
    {
        j = 4;
        while (--j > -1)
        {
            ret = (ret << 1) | (list[i][j] != '.');
        }
    }
    return  (ret);
}