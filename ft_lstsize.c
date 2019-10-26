/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:37:41 by jwebber           #+#    #+#             */
/*   Updated: 2019/10/26 14:50:41 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_lstsize(t_list *list)
{
	if (list == NULL)
		return (0);
	return (ft_lstsize(list->next) + 1);
}

size_t	ft_find_size(size_t len)
{
	size_t size;

	size = 2;
	while (size * size < len)
		size++;
	return (size);
}
