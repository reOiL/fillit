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
# include "ft_pair.h"

void			ft_usage(void);
void			ft_error(int close);
t_list			*ft_parse(char *file);
void			ft_fill_del(void *data, size_t size);
size_t			ft_lst_size(t_list *lst);
void			ft_map_clean(char **map);
char			**ft_map_alloc(size_t size);
char			**ft_brute(t_list *lst, size_t len);
int	            ft_tet_to_num(char **list);
t_quad			ft_tet_coordinate(char **list);
int             *min_max(int *c);
int             tet_is_valid(int c);
char            **to_good_tetrim(char **list);
void			ft_print_result(char **a, size_t len);
int				ft_map_size(int tetrim_kolvo);

#endif
