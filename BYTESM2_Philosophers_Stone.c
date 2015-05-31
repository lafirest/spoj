//TLE
//这个是简单的把lisp代码翻译成了C代码,效率变化不大
#include<stdio.h>
#include<malloc.h>
#define max(a,b) ((a) > (b) ? (a) : (b))

int
calc_max(int arr[][100], int x, int y, int r)
{
    int temp = 0;
    if(x == 0)
        return arr[x][y];
    else 
    {
        if(y == 0)
            temp = calc_max(arr, x - 1, y + 1, r);
        else if (y == r)
            temp = calc_max(arr, x - 1, y - 1, r);
        else
            temp = max(calc_max(arr, x - 1, y - 1, r), calc_max(arr, x - 1, y + 1, r));

        return arr[x][y] + max(temp, calc_max(arr, x - 1, y, r));
    }
}

int
get_max(int arr[][100], int c, int r)
{
    int i = 0;
    int max = 0;
    int ciValue = 0;
    c -= 1;
    r -= 1;
    for ( i = 0; i <= r; ++i)
    {
        ciValue = calc_max(arr, c, i, r);
        if (ciValue > max)
            max = ciValue;
    }
    return max;
}

int
main(void)
{
    int times = 0;
    int i,j,c,r = 0;
    int arr[100][100] ={0};
    scanf("%d", &times);
    while(times--)
    {
        scanf("%d %d", &c, &r);
        for(i = 0; i < c; ++i)
            for(j = 0; j < r; ++j)
                scanf("%d", &arr[i][j]);
        printf("%d\n", get_max(arr, c, r));

    }
    return 0;
}
