//
// Created by Johnny Webber on 30/09/2019.
//

#include "fillit.h"


char	**ft_map_alloc(size_t size)
{
	char 	**ret;
	size_t	i;

	ret = ft_memalloc(sizeof(char *) * (size + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ret[i] = ft_strnew(size);
		if (!ret[i])
		{
			ft_remove_sstr(&ret);
			return (NULL);
		}
		ft_memset((void *)ret[i], '.', size);
		i++;
	}
	return (ret);
}