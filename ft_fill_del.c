//
// Created by Johnny Webber on 29/09/2019.
//

#include "fillit.h"

void	ft_fill_del(void *data, size_t size)
{
	//char		**a;
	//size_t		i;

	(void)size;
	//a = data;
	//if (a == NULL)
	//	return ;
	//i = 0;
	//while (i < 4)
	//{
	//	ft_strdel(&a[i]);
	//	i++;
	//}
	ft_memdel(&data);
}