#include "fillit.h"
#include <stdio.h>

int     tet_is_valid(int c)
{
    int     w;
    int     lst[19];

    lst[0] = 69905;
    lst[1] = 65551;
    lst[2] = 65587;
    lst[3] = 65811;
    lst[4] = 66083;
    lst[5] = 65559;
    lst[6] = 65607;
    lst[7] = 66338;
    lst[8] = 66321;
    lst[9] = 65649;
    lst[10] = 65652;
    lst[11] = 65841;
    lst[12] = 65650;
    lst[13] = 66098;
    lst[14] = 65575;
    lst[15] = 65635;
    lst[16] = 65842;
    lst[17] = 65590;
    lst[18] = 66097;
    w = 0;
    while(w < 19)
    {
        if (lst[w++] == c)
            return (1);
    }
    return (0);
}


char    **to_good_tetrim(char **list)
{
    int         i;
    int         j;
    char        **tmp;
    int         *c;
    int         tp;


    c = ft_memalloc(4);
    c = min_max(ft_tet_coordinate(list));
    tmp = (char **)malloc(sizeof(char*) * 4);
    i = 0;
    tp = c[2];
    while (i < 4)
    {
        j = 0;
        tmp[i] = (char *)malloc(sizeof(char) * 5);
        while (j < 4)
        {
            if(c[2] < (c[3] + 1) && c[0] < (c[1] + 1))
                tmp[i][j] = list[c[0]][c[2]];
            else
                tmp[i][j] = '.';
            j++;
            c[2]++;
        }
        tmp[i][j] = '\0';
        i++;
        c[2] = tp;
        c[0]++;
    }
    return (tmp);
}

int main()
{
    char    *tmp1[4] = {"....","..x.","..x.","..xx"};
    char    *tmp2[4] = {"....","....","..xx","..xx"};
    char    *tmp3[4] = {"....","xxxx","....","...."};
    char    *tmp4[4] = {"....","....","..xx","xx.."};
    char    *tmp5[4] = {"....","..x.","....","..xx"};
    char    *tmp6[4] = {"....","....",".xx.","..xx"};
    char    *tmp7[4] = {"....","....","....","...."};
    char    *tmp8[4] = {"....","....","....","...."};

    printf("%d \n", tet_is_valid(ft_tet_to_num(to_good_tetrim(tmp1))));
    printf("%d \n", tet_is_valid(ft_tet_to_num(to_good_tetrim(tmp2))));
    printf("%d \n", tet_is_valid(ft_tet_to_num(to_good_tetrim(tmp3))));
    printf("%d \n", tet_is_valid(ft_tet_to_num(to_good_tetrim(tmp4))));
    printf("%d \n", tet_is_valid(ft_tet_to_num(to_good_tetrim(tmp5))));
    printf("%d \n", tet_is_valid(ft_tet_to_num(to_good_tetrim(tmp6))));
    printf("%d \n", tet_is_valid(ft_tet_to_num(to_good_tetrim(tmp7))));
    printf("%d \n", tet_is_valid(ft_tet_to_num(to_good_tetrim(tmp8))));

    return 0;

}