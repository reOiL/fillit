//
// Created by Johnny Webber on 30/09/2019.
//

#include "fillit.h"


int		place_block(char **field, t_list *lst, size_t len, char c)
{
	if (lst == NULL)
		return (-1);

	return (1);
}

char 	**ft_brute2(char **ret, size_t len, t_list *lst, int index)
{

}

char	**ft_brute(t_list *lst, size_t len)
{
	char	**ret;

	if (!(ret = ft_map_alloc(len)))
		return (NULL);
	ft_brute2(ret, len, lst, 0);
	return (ret);
}