/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:05:54 by jwebber           #+#    #+#             */
/*   Updated: 2019/10/26 15:09:49 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_tet_to_num(char **list)
{
	int				i;
	int				j;
	unsigned int	ret;

	i = 4;
	ret = 1;
	while (--i > -1)
	{
		j = 4;
		while (--j > -1)
			ret = (ret << 1) | (list[i][j] != '.');
	}
	return (ret);
}

int	check_tet(char **tet)
{
	int ret;

	ret = ft_tet_to_num(tet);
	return (ret == 69905 || ret == 65551 || ret == 65587 || ret == 65811 ||
			ret == 66083 || ret == 65559 || ret == 65607 || ret == 66338 ||
			ret == 66321 || ret == 65649 || ret == 65652 || ret == 65841 ||
			ret == 65650 || ret == 66098 || ret == 65575 || ret == 65635 ||
			ret == 65842 || ret == 65590 || ret == 66097);
}

int	check_valid_inp(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	return (1);
}
