//
// Created by Johnny Webber on 30/09/2019.
//

#include "fillit.h"

void 	ft_print(char **a, size_t len)
{
	size_t i;
	size_t j;
	char color[] = "\e[40;30m";

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (a[i][j] != '.')
				color[6] = color[3] = ('0' + (a[i][j] % 7));
			else
				color[6] = color[3] = '7';
			ft_putstr(color);
			ft_putchar(a[i][j]);
			ft_putstr("\v\v\v");
			ft_putstr("\e[0m");
			j++;
			color[6] = color[3] = '0';
		}
		ft_putchar('\n');
		i++;
	}
}

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
	return (-1);
}
int 	ft_brute2(char **ret, size_t len, t_list *lst, char index)
{
	int 	k;

	if (!ret)
		return (-1);
	if (!lst)
		return (0);
	ft_putendl("\e[48;5;16m----------------------------------------------------\e[0m");
	k = place_block(ret, (t_quad *)lst->content, len, index);
	ft_print(ret, len);
	if (k != 1)
	{
		remove_block(ret, index);
		return (0);
	}
	return (ft_brute2(ret, len, lst->next, index + (char)1));
}

char	**ft_brute(t_list *lst, size_t len)
{
	char	**ret;

	if (!(ret = ft_map_alloc(len)))
		return (NULL);
	ft_brute2(ret, len, lst, 'A');
	return (ret);
}