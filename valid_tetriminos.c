
#include <stdio.h>
#include <stdlib.h>

int     tet_is_valid(int c)
{
    int     lst[19];
    int     k;

    k = 0;
    lst = {69905, 65551, 65587, 65811, 66083, 65559, 65607, 66338,
           66321, 65649, 65652, 65841, 65650, 66098, 65575, 65635,
           65842, 65590, 66097};
    while(k < 19)
    {
        if (lst[k] == c)
            return (1);
        k++;
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
    int     k;

    i = 0;
    k = 0;
    coord = (int *)malloc(sizeof(int) * 4);
    while (i < 4)
    {
        j = 0;
        while(j < 4 && k < 4)
        {
         if (list[i][j] == '.')
             j++;
         else
         {
             coord[k] = i * 10 + j;
             j++;
         }
        i++;
         }
    return (coord);
}

int         *min_max(int *c)
{
    int     k;
    int minmax[4],

    k = 0;
    minmax = (int *)malloc(sizeof(int) * 4);
    while(k < 4)
    {
        minmax[0] = c[k] / 10;
        minmax[1] = c[k] / 10;
        minmax[2] = c[k] % 10;
        minmax[3] = c[k] % 10;
        if (minmax[0] > c[k] / 10)
            minmax[0] = c[k] / 10);
        if (minmax[1] < c[k] / 10)
            minmax[1] = c[k] / 10);
        if (minmax[2] > c[k] % 10)
            minmax[2] = c[k] % 10);
        if (minmax[3] < c[k] % 10)
            minmax[3] = c[k] % 10);
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
    int         k;

    c = (int *)malloc(sizeof(int) * 4);
    c = min_max(ft_tet_coordinate(**list));
    tmp = (char **)malloc(sizeof(char*) * 4);
    i = 0;
    k = 0;
    while (i < 4)
    {
        tmp[i] = (char *)malloc(sizeof(char) * 5);
        while (j < 4)
            if(c[3] < c[4])
                tmp[i][j++] = list[c[1]][c[3]++];
            else
                tmp[i][j++] = '.';
        tmp[i][j] = '\0';
        j = 0;
        i++;
        if(c[1] < c[2])
            c[1]++;
    }
    return (tmp);
}

int main()
{

    char    *tmpz[4] = {"....","....","..xx","..xx"};
    char    *ideal[4] = {"xx..","xx..","....","...."};

    printf("%d \n", ft_tet_to_num(ideal));
    printf("%d \n", ft_tet_to_num(to_good_tetrim(tmpz)));

    return 0;
}