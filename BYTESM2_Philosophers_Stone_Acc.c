//这里的解法是从第二层开始向上构建各个位置的最优解,
//然后直接取出最后一行的最优解即可.这个相当于递归方法
//倒过来用,好处是每个位置的最优解只需要求解一次
#include<stdio.h>
#include<malloc.h>
#define max(a,b) ((a) > (b) ? (a) : (b))

void
build(int arr[][100], int i, int j, int c, int r)
{
    int px = i - 1;
    int temp = 0;
    if(j == 0)
        temp = arr[px][j + 1];
    else if(j == r - 1)
        temp = arr[px][j - 1];
    else 
        temp = max(arr[px][j + 1], arr[px][j - 1]);

    arr[i][j] += max(arr[px][j], temp);
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

        for(i = 1; i < c; ++i)
            for(j = 0; j < r; ++j)
                build(arr, i, j, c, r);

        int max = 0;
        for(j = 0; j < r; ++j)
            if(arr[c-1][j] > max)
                max = arr[c-1][j];
        
        printf("%d\n", max);
    }
    return 0;
}
