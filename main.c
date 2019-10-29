/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:28:51 by jwebber           #+#    #+#             */
/*   Updated: 2019/10/29 15:55:32 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_list *lst;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit file");
		return (0);
	}
	lst = ft_parse(argv[1]);
	if (!lst)
		ft_error(1);
	ft_brute(lst);
	ft_lstdel(&lst, ft_fill_del);
	return (0);
}
