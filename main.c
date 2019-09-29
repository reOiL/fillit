/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:12:46 by jwebber           #+#    #+#             */
/*   Updated: 2019/09/29 14:52:23 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	t_list	*lst;

	if (argc != 2)
	{
		ft_usage();
		return (0);
	}
	lst = ft_parse(argv[1]);
	if (!lst)
		ft_error(1);

	ft_lstdel(&lst, ft_fill_del);
	return (0);
}
