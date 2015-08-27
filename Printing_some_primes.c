// 筛法
#include <stdio.h>
#include <math.h>

#define MAX 100000010
char array[MAX]; // 重点是这儿,使用其他类型都会超时,不清除bitarray会不会更快

int
main(void)
{
    // 筛选素数
    int sq = sqrt(MAX) + 1;
    for(int i = 2; i <= sq; ++i)
    {
        if(array[i])
            continue;

        for(int j = i + i; j <= MAX; j += i)
            array[j] = 1;
    }

    printf("2\n"); 
    for(int i = 3, j = 0; i <= MAX; ++i)
    {
        if(array[i])
            continue;

        ++j;

        if(j == 100)
        {
            printf("%d\n", i);
            j = 0;
        }

    }

    return 0;
}
