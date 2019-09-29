//
// Created by Johnny Webber on 29/09/2019.
//

#include "fillit.h"

unsigned int	ft_tet_to_num(char **list)
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
		{
			ret = (ret << 1) | (list[i][j] != '.');
		}
	}
	return  (ret);
}