//
// Created by Johnny Webber on 30/09/2019.
//

#include "fillit.h"

size_t	ft_lst_size(t_list *lst)
{
	if (lst == NULL)
		return (0);
	return ft_lst_size(lst->next) + 1;
}