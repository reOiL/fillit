#include <stdio.h>
#include <stdlib.h>

int     tet_is_valid(int c)
{
    int     lst[19] =  {69905, 65551, 65587, 65811, 66083, 65559, 65607, 66338, 66321, 65649, 65652, 65841, 65650, 66098, 65575, 65635, 65842, 65590, 66097};
    int     w;
    w = 0;
    while(w < 19)
    {
        if (lst[w] == c)
            return (1);
        w++;
    }
    return (0);
}

int    ft_tet_to_num(char **list)
{
    int                i;
    int                j;
    unsigned int    ret;

    i = 4;
    ret = 1;
    while (--i > -1)
    {
        j = 4;
        while (--j > -1)
        {
            ret = (ret << 1) | (list[i][j] != '.');
        }
    }
    return  (ret);
}

int     *ft_tet_coordinate(char **list)
{
    int     i;
    int     j;
    int     *coord;
    int     p;

    i = 0;
    p = 0;
    coord = (int *)malloc(sizeof(int) * 4);
    while (i < 4)
    {
        j = 0;
        while(j < 4 && p < 4)
        {
            if (list[i][j] == '.')
                j++;
            else
            {
                coord[p] = i * 10 + j;
                j++;
                p++;

            }
        }
        i++;
    }
    return (coord);
}


int         *min_max(int *c)
{
    int     b;
    int     *minmax;
    int     k;

    k = 0;
    minmax = (int *)malloc(sizeof(int) * 4);
    minmax[0] = c[k] / 10;
    minmax[1] = c[k] / 10;
    minmax[2] = c[k] % 10;
    minmax[3] = c[k] % 10;
    while(k < 4)
    {
        if (minmax[0] > c[k] / 10)
            minmax[0] = c[k] / 10;
        if (minmax[1] < c[k] / 10)
            minmax[1] = c[k] / 10;
        if (minmax[2] > c[k] % 10)
            minmax[2] = c[k] % 10;
        if (minmax[3] < c[k] % 10)
            minmax[3] = c[k] % 10;
        k++;
    }
    return (minmax);
}

char    **to_good_tetrim(char **list)
{
    int         i;
    int         j;
    char        **tmp;
    int         *c;
    int         tp;


    c = (int *)malloc(sizeof(int) * 4);
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
            printf("%c", tmp[i][j]);
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