//
// Created by reoil on 14.10.2019.
//

#ifndef FILLIT_FILLIT_H
#define FILLIT_FILLIT_H

# include "libft/libft.h"
# include "ft_pair.h"
# include "get_next_line.h"

void	ft_error(int close);
void	ft_fill_del(void *data, size_t size);
t_list	*ft_parse(char *file);
size_t	ft_lstsize(t_list *list);
t_quad	ft_tet_coordinate(char **list);
void	ft_brute(t_list *lst);
char	**ft_normalize(char **buff);
void	ft_swap(char *a, char *b);
void	ft_swap_ptr(void **a, void **b);
void	ft_print_result(char **a, size_t len);
size_t	ft_find_size(size_t len);
size_t	ft_find_size(size_t len);
int		ft_tet_to_num(char **list);
int		check_tet(char **tet);
int		check_valid_inp(char *str);
t_list	*ft_del_and_close(int fd, t_list *lst, char **buff);

#endif //FILLIT_FILLIT_H
