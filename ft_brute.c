//
// Created by reoil on 14.10.2019.
//

#include "fillit.h"

size_t ft_find_size(size_t len) {
    size_t size;

    size = 2;
    while (size * size < len)
        size++;
    return (size);
}


char **ft_create_field(size_t len) {
    char **ret;
    size_t i;

    ret = ft_memalloc(sizeof(char *) * len);
    if (!ret)
        return (NULL);
    i = 0;
    while (i < len) {
        ret[i] = ft_strnew(len);
        if (!ret[i]) {
            ft_remove_sstr(&ret);
            return (NULL);
        }
        ft_memset(ret[i], '.', len);
        i++;
    }
    return (ret);
}

int place_block(char **field, t_quad *block, size_t len, char c, t_pair start) {
    t_pair iter;

    iter.x = start.x;
    while (iter.x < len) {
        if (iter.x + block->p1.x >= len ||
            iter.x + block->p2.x >= len ||
            iter.x + block->p3.x >= len ||
            iter.x + block->p4.x >= len)
            return (0);
        iter.y = start.y;
        while (iter.y < len) {
            if (iter.y + block->p1.y >= len ||
                iter.y + block->p2.y >= len ||
                iter.y + block->p3.y >= len ||
                iter.y + block->p4.y >= len)
                break;
            if (field[iter.y + block->p1.y][iter.x + block->p1.x] == '.' &&
                field[iter.y + block->p2.y][iter.x + block->p2.x] == '.' &&
                field[iter.y + block->p3.y][iter.x + block->p3.x] == '.' &&
                field[iter.y + block->p4.y][iter.x + block->p4.x] == '.') {
                field[iter.y + block->p1.y][iter.x + block->p1.x] = c;
                field[iter.y + block->p2.y][iter.x + block->p2.x] = c;
                field[iter.y + block->p3.y][iter.x + block->p3.x] = c;
                field[iter.y + block->p4.y][iter.x + block->p4.x] = c;
                return (1);
            }
            iter.y++;
        }
        iter.x++;
    }
    return (0);
}

void ft_remove_block(char **field, size_t size, char word) {
    t_pair iter;

    iter.x = 0;
    while (iter.x < size) {
        iter.y = 0;
        while (iter.y < size) {
            if (field[iter.x][iter.y] == word)
                field[iter.x][iter.y] = '.';
            iter.y++;
        }
        iter.x++;
    }
}

int ft_brute2(char **field, t_list *lst, size_t size, char word) {
    t_pair iter;
    static int i = 0;

    if (lst == NULL)
        return (1);
    iter.y = 0;
    while (iter.y < size) {
        iter.x = 0;
        while (iter.x < size) {
            if (place_block(field, (t_quad *) lst->content, size, word, iter)) {
                //ft_print_result(field, size);
                //printf("%i\n", i);
                i++;
                if (ft_brute2(field, lst->next, size, word + 1))
                    return (1);
                else
                    ft_remove_block(field, size, word);
            }
            iter.x++;
        }
        iter.y++;
    }
    return (0);
}

char **ft_brute(t_list *lst) {
    size_t field_size;
    char **field;

    field_size = ft_find_size(ft_lstsize(lst) * 4);
    field = ft_create_field(field_size);
    while (!ft_brute2(field, lst, field_size, 'A')) {
        field_size++;
        ft_remove_sstr(&field);
        field = ft_create_field(field_size);
    }
    ft_print_result(field, field_size);
    return (field);
}