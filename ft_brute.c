//
// Created by Johnny Webber on 30/09/2019.
//

#include "fillit.h"

void		remove_block(char **field, char c)
{
	size_t 	i;
	size_t 	j;

	if (field == NULL)
		return ;
	i = 0;
	while (field[i])
	{
		j = 0;
		while (field[i][j])
		{
			if (field[i][j] == c)
				field[i][j] = '.';
			j++;
		}
		i++;
	}
}
/*
int		place_block(char **field, t_quad *block, size_t len, char c)
{
	//TODO: refactoring me
	size_t 	i;
	size_t 	j;
	int 	retry;
	t_pair	p;

	if (block == NULL || field == NULL)
		return (-1);
	j = 0;
	p.x = 0;
	p.y = 0;
	while (j < 4)
	{
		i = 0;
		retry = 0;
		while (i < 4)
		{
			if (i + p.y >= len)
				return (-1);

			if (field[i + p.y][j + p.x] != '.' && block[i % 5][j % 5] != '.')
			{
				ft_putendl("Impossible:");
//				ft_print(field, len);
//				ft_putchar('\n');
				remove_block(field, c);
				retry = 1;
				p.x++;
				break ;
			}
			if (block[i % 5][j % 5] != '.')
				field[i + p.y][j + p.x] = c;
			i++;
		}
		if (retry == 0)
			j++;
		else
		{
			j = 0;
			if (p.x >= len)
			{
				p.y++;
				p.x = 0;
			}
		}
	}
	return (1);
}
*/
int		place_block(char **field, t_quad *block, size_t len, char c)
{
	t_pair	iter;

	iter.x = 0;
	while (iter.x < len)
	{
		if (iter.x + block->p1.x >= len ||
			iter.x + block->p2.x >= len ||
			iter.x + block->p3.x >= len ||
			iter.x + block->p4.x >= len)
			return (0);
		iter.y = 0;
		while (iter.y < len)
		{
			if (iter.y + block->p1.y >= len ||
				iter.y + block->p2.y >= len ||
				iter.y + block->p3.y >= len ||
				iter.y + block->p4.y >= len)
				break;
			if (field[iter.y + block->p1.y][iter.x + block->p1.x] == '.' &&
					field[iter.y + block->p2.y][iter.x + block->p2.x] == '.' &&
					field[iter.y + block->p3.y][iter.x + block->p3.x] == '.' &&
					field[iter.y + block->p4.y][iter.x + block->p4.x] == '.')
			{
				field[iter.y + block->p1.y][iter.x + block->p1.x] = c;
				field[iter.y + block->p2.y][iter.x + block->p2.x] = c;
				field[iter.y + block->p3.y][iter.x + block->p3.x] = c;
				field[iter.y + block->p4.y][iter.x + block->p4.x] = c;
				return (1);
			}
			iter.y++;
		}
		iter.x++;
	}
	return (0);
}
int 	ft_brute2(char **ret, size_t len, t_quad	**array/*t_list *lst*/, char index)
{
	int 	k;

	if (!ret)
		return (-1);
	if (!*array)
		return (0);
	//ft_putendl("\e[48;5;16m----------------------------------------------------\e[0m");
	k = place_block(ret, (t_quad *)*array, len, index);
	//ft_print_result(ret, len);
	if (k != 1)
	{
		remove_block(ret, index);
		return (-1);
	}
	return (ft_brute2(ret, len, array + 1, index + (char)1));
}

t_list	*ft_lst_back(t_list *lst)
{
	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	return (ft_lst_back(lst->next));
}

t_quad	**ft_lst_to_array(t_list	*lst, size_t len)
{
	size_t	i = 0;
	t_quad	**ret = (t_quad**)ft_memalloc((len + 1) * sizeof(t_quad *));

	while (lst)
	{
		ret[i] = lst->content;
		lst = lst->next;
		i++;
	}
	return (ret);
}

#include <stdio.h>
char	**ft_brute(t_list *lst, size_t len)
{
	char	**ret;
	t_quad	**array = ft_lst_to_array(lst, len);

	if (!(ret = ft_map_alloc(len + 1)))
		return (NULL);
	while (1)
	{
		if (ft_brute2(ret, len + 1, array/*lst*/, 'A') == 0)
			break ;
		ft_print_result(ret, len + 1);
		ft_putendl("Brute failed");
		ft_map_clean(ret);
	}
	return (ret);
}