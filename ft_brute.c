/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brute.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:38:29 by jwebber           #+#    #+#             */
/*   Updated: 2019/10/26 15:00:27 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_field(size_t len)
{
	char	**ret;
	size_t	i;

	ret = ft_memalloc(sizeof(char *) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = ft_strnew(len);
		if (!ret[i])
		{
			ft_remove_sstr(&ret);
			return (NULL);
		}
		ft_memset(ret[i], '.', len);
		i++;
	}
	return (ret);
}

int		is_possible(t_quad *block, size_t len, t_pair start, char **field)
{
	t_pair	*ptr;
	int		i;

	i = 0;
	ptr = &block->p1;
	while (i < 4)
	{
		if (start.y + ptr->y >= (int)len || start.x + ptr->x >= (int)len)
			return (0);
		if (field[start.y + ptr->y][start.x + ptr->x] != '.')
			return (0);
		ptr++;
		i++;
	}
	return (1);
}

void	ft_set_block(char **field, t_pair pos, t_quad block, char word)
{
	t_pair	*ptr;
	int		i;

	ptr = &block.p1;
	i = 0;
	while (i < 4)
	{
		field[pos.y + ptr->y][pos.x + ptr->x] = word;
		ptr++;
		i++;
	}
}

int		ft_brute2(char **field, t_list *lst, size_t size, char word)
{
	t_pair		iter;

	if (lst == NULL)
		return (1);
	iter.y = 0;
	while (iter.y < (int)size)
	{
		iter.x = 0;
		while (iter.x < (int)size)
		{
			if (is_possible((t_quad *)lst->content, size, iter, field))
			{
				ft_set_block(field, iter, *(t_quad *)lst->content, word);
				if (ft_brute2(field, lst->next, size, word + 1))
					return (1);
				else
					ft_set_block(field, iter, *(t_quad *)lst->content, '.');
			}
			iter.x++;
		}
		iter.y++;
	}
	return (0);
}

void	ft_brute(t_list *lst)
{
	size_t	field_size;
	char	**field;

	field_size = ft_find_size(ft_lstsize(lst) * 4);
	field = ft_create_field(field_size);
	while (!ft_brute2(field, lst, field_size, 'A'))
	{
		field_size++;
		ft_remove_sstr(&field);
		field = ft_create_field(field_size);
	}
	ft_print_result(field, field_size);
	ft_remove_sstr(&field);
}
