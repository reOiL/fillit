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

void	ft_usage(void);
void	ft_error(int close);
t_list	*ft_parse(char *file);
void	ft_fill_del(void *data, size_t size);

#endif
