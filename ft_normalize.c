/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:30:18 by jwebber           #+#    #+#             */
/*   Updated: 2019/10/26 15:38:03 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_up(char **buff)
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

int		ft_find_right(char **buff)
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
				break ;
			}
			j++;
		}
		i++;
	}
	return (f == 1000 ? -1 : f);
}

void	ft_normalize_left(char **buff, t_pair swap_pair)
{
	int	i;
	int	j;

	i = 0;
	while (i < swap_pair.x)
	{
		j = 1;
		while (j < 4)
		{
			ft_swap_ptr((void **)&buff[j - 1], (void **)&buff[j]);
			j++;
		}
		i++;
	}
}

void	ft_normalize_right(char **buff, t_pair swap_pair)
{
	int	i;
	int	j;
	int	d;

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
}

char	**ft_normalize(char **buff)
{
	t_pair	swap_pair;

	if (!buff)
		return (NULL);
	swap_pair.x = ft_find_up(buff);
	swap_pair.y = ft_find_right(buff);
	if (swap_pair.x == -1 || swap_pair.y == -1)
		return (buff);
	ft_normalize_left(buff, swap_pair);
	ft_normalize_right(buff, swap_pair);
	return (buff);
}
