//
// Created by Johnny Webber on 09/10/2019.
//

#include "fillit.h"

int		ft_map_size(int tetrim_kolvo)
{
	int     n;

	n = 2;
	while (tetrim_kolvo * 4 > n * n)
		n++;
	return (n);
}