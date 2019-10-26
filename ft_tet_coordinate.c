/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tet_coordinate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:55:46 by jwebber           #+#    #+#             */
/*   Updated: 2019/10/26 15:01:22 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_quad	ft_tet_coordinate(char **list)
{
	t_pair	*ptr;
	int		p;
	t_quad	ret;
	t_pair	iter;

	iter.x = 0;
	p = 0;
	ptr = &ret.p1;
	while (iter.x < 4)
	{
		iter.y = 0;
		while (iter.y < 4 && p < 4)
		{
			if (list[iter.x][iter.y] != '.')
			{
				ptr->y = iter.x;
				ptr->x = iter.y;
				p++;
				ptr++;
			}
			iter.y++;
		}
		iter.x++;
	}
	return (ret);
}
