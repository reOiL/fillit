//
// Created by Johnny Webber on 03/10/2019.
//

#include "fillit.h"

void	ft_print_result(char **a, size_t len)
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