/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:22:26 by lbernard          #+#    #+#             */
/*   Updated: 2019/09/26 21:08:47 by lbernard         ###   ########.fr       */
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

int		valid_tetriminos(int fd)
{
	int			valid_fd;
	char		**valid_list;
	int			valid_num;
	char		**list;
	int			num;

}
