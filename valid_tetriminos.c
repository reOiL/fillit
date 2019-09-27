/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:22:26 by lbernard          #+#    #+#             */
/*   Updated: 2019/09/27 14:28:14 by lbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		convert_num(char **list)
{
	int		i;
	int		j;
	int		b;
	int		ret;
	int		bin;

	i = 4;
	j = 4;
	bin = 1;
	ret = 0;
	while (--i > -1)
	{
		while (--j > -1)
		{
			if (list[i][j] == '.')
				b = 0;
			else
				b = 1;
			ret = ret + bin * b;
			bin = 2 * bin;
		}
		j = 4;
	}
	return  (ret);
}

int		check_valid(char **list)
{
	int		i;
	int		j;

	i = 0;
	while (*list[i])
	{
		j = 0;
		if ((i - 4) % 5 != 0)
		{
			while (list[i][j])
				j++;
			if (j == 4)
				i++;
			else
				return (-1);
		}
		j = 0;
		if ((i - 4) % 5 == 0 && list[i][j] == '\n' && list[i][j + 1] == '\0')
			i++;
		else
			return (-1);
	}
	return (1);
}

int		valid_tetriminos(int fd)
{
	int			valid_fd;
	char		**valid_list;
	int			valid_num;
	char		**list;
	int			num;

}
