//
// Created by Johnny Webber on 30/09/2019.
//

#include "fillit.h"

void	ft_map_clean(char **map)
{
	int 	i;
	size_t 	len;

	if (map == NULL || map[0] == NULL)
		return;
	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		ft_memset(map[i], '.', len);
		i++;
	}
}