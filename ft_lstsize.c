//
// Created by reoil on 14.10.2019.
//

#include "fillit.h"

size_t ft_lstsize(t_list *list) {
    if (list == NULL)
        return (0);
    return ft_lstsize(list->next) + 1;
}