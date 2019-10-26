#include "fillit.h"

int main(int argc, char **argv) {
    t_list *lst;
    if (argc != 2) {
        ft_putendl("usage: fillit file");
        return (0);
    }
    lst = ft_parse(argv[1]);
    if (!lst)
        ft_error(1);
    ft_brute(lst);
    ft_lstdel(&lst, ft_fill_del);
    return 0;
}