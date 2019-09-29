//
// Created by Johnny Webber on 29/09/2019.
//

#include <fcntl.h>
#include "fillit.h"

char 	**ft_read_node(int fd)
{
	char	**ret;
	int		i;
	int		code;

	if (fd < 0)
		return (NULL);
	ret = ft_memalloc(sizeof(char **) * 4);
	if (!ret)
		return (NULL);
	 i = 0;
	 while (i < 4)
	 {
		code = get_next_line(fd, &ret[i]);
		if (code == -1 || (code == 0 && i != 4) || ft_strlen(ret[i]) != 4)
		{
			ft_fill_del((void **)ret, 0);
			return (NULL);
		}
		i++;
	 }
	return (ret);
}

int 	ft_skip(int fd)
{
	char	*buff;
	int		code;

	code = get_next_line(fd, &buff);
	if (code == -1)
		return (-1);
	if (code == 0)
		return (0);
	if(ft_strcmp(buff, "") != 0)
	{
		ft_strdel(&buff);
		return (-1);
	}
	ft_strdel(&buff);
	return (1);
}

t_list	*ft_parse(char *file)
{
	int		fd;
	t_list	*lst;
	char 	**buff;
	int 	code;

	fd = open(file, O_RDONLY);
	lst = NULL;
	if (fd < 0)
		return (NULL);
	while (1)
	{
		buff = ft_read_node(fd);
		code = ft_skip(fd);
		if (!buff || code < 0)
		{
			ft_lstdel(&lst, ft_fill_del);
			ft_memdel((void **) &buff);
			return (NULL);
		}
		ft_lstadd(&lst, ft_lstnew((void *)buff, sizeof(char *) * 4));
		ft_memdel((void **) &buff);
		if (code == 0)
			break;
	}
	close(fd);
	return (lst);
}