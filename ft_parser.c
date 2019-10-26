//
// Created by reoil on 14.10.2019.
//

#include <fcntl.h>
#include "fillit.h"

int check_valid_inp(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

char 	**ft_read_node(int fd)
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

int    ft_tet_to_num(char **list)
{
	int                i;
	int                j;
	unsigned int    ret;

	i = 4;
	ret = 1;
	while (--i > -1)
	{
		j = 4;
		while (--j > -1)
		{
			ret = (ret << 1) | (list[i][j] != '.');
		}
	}
	return  (ret);
}

#include <stdio.h>
int check_tet(char **tet)
{
	int ret;

	ret = ft_tet_to_num(tet);
	return (ret == 69905 || ret == 65551 || ret == 65587 || ret == 65811 ||
	        ret == 66083 || ret == 65559 || ret == 65607 || ret == 66338 ||
	        ret == 66321 || ret == 65649 || ret == 65652 || ret == 65841 ||
	        ret == 65650 || ret == 66098 || ret == 65575 || ret == 65635 ||
	        ret == 65842 || ret == 65590 || ret == 66097);
	printf("%d\n", ret);
	return (1);
}

void ft_push_back(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
		return ft_lstadd(lst, new);
	return ft_push_back(&((*lst)->next), new);
}
t_list	*ft_parse(char *file)
{
    int		fd;
    t_list	*lst;
    char 	**buff;
    int 	code;
    t_quad	quad;

    fd = open(file, O_RDONLY);
    lst = NULL;
    if (fd < 0)
        return (NULL);
    while (1)
    {
        buff = ft_normalize(ft_read_node(fd));
        code = ft_skip(fd);
        if (!buff || code < 0 || !check_tet(buff))
        {
            ft_lstdel(&lst, ft_fill_del);
            ft_remove_sstr(&buff);
            return (NULL);
        }
        quad = ft_tet_coordinate(buff);
		ft_push_back(&lst, ft_lstnew((void *)&quad, sizeof(t_quad)));
        ft_remove_sstr(&buff);
        if (code == 0)
            break;
    }
    close(fd);
    return (lst);
}