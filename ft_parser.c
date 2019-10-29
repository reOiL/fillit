/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:04:42 by jwebber           #+#    #+#             */
/*   Updated: 2019/10/29 16:02:24 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"

char	**ft_read_node(int fd)
{
	char	**ret;
	int		i;
	int		code;

	if (fd < 0)
		return (NULL);
	ret = ft_memalloc(sizeof(char **) * 5);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		code = get_next_line(fd, &ret[i]);
		if (code == -1 || (code == 0 && i != 4) ||
				ft_strlen(ret[i]) != 4 || !check_valid_inp(ret[i]))
		{
			ft_remove_sstr(&ret);
			return (NULL);
		}
		i++;
	}
	return (ret);
}

int		ft_skip(int fd)
{
	char	*buff;
	int		code;

	code = get_next_line(fd, &buff);
	if (code == -1)
		return (-1);
	if (code == 0)
		return (0);
	if (ft_strcmp(buff, "") != 0)
	{
		ft_strdel(&buff);
		return (-1);
	}
	ft_strdel(&buff);
	return (1);
}

void	ft_push_back(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
		return (ft_lstadd(lst, new));
	return (ft_push_back(&((*lst)->next), new));
}

t_list	*ft_parse(char *file)
{
	int		fd;
	t_list	*lst;
	char	**buff;
	int		code;
	t_quad	quad;

	fd = open(file, O_RDONLY);
	lst = NULL;
	if (fd < 0)
		return (NULL);
	while (1)
	{
		buff = ft_normalize(ft_read_node(fd));
		code = ft_skip(fd);
		if (!buff || code < 0 || !check_tet(buff) || ft_lstsize(lst) > 26)
			return (ft_del_and_close(fd, lst, buff));
		quad = ft_tet_coordinate(buff);
		ft_push_back(&lst, ft_lstnew((void *)&quad, sizeof(t_quad)));
		ft_remove_sstr(&buff);
		if (code == 0)
			break ;
	}
	close(fd);
	return (lst);
}
