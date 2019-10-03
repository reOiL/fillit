/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:43:16 by jwebber           #+#    #+#             */
/*   Updated: 2019/09/29 14:51:58 by jwebber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include "get_next_line.h"

void			ft_usage(void);
void			ft_error(int close);
t_list			*ft_parse(char *file);
void			ft_fill_del(void *data, size_t size);
int	            ft_tet_to_num(char **list);
int             *ft_tet_coordinate(char **list);
int             *min_max(int *c);
int             tet_is_valid(int c);
char            **to_good_tetrim(char **list);

#endif
