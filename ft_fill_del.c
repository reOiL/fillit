/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:36:44 by jwebber           #+#    #+#             */
/*   Updated: 2019/10/26 15:18:21 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

void	ft_fill_del(void *data, size_t size)
{
	(void)size;
	ft_memdel(&data);
}

t_list	*ft_del_and_close(int fd, t_list *lst, char **buff)
{
	ft_lstdel(&lst, ft_fill_del);
	ft_remove_sstr(&buff);
	close(fd);
	return (NULL);
}
