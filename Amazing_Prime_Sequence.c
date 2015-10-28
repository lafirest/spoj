// 这道题目还是采用自底构造筛法来做
#include <stdio.h>

#define MAX 10000010
#define bigint long long int

int fset[MAX];
bigint aset[MAX];

int 
main(void)
{
    // 遍历所有偶数,它们的最小质因数都是2
    for(int i = 2; i < MAX; i += 2)
        fset[i] = 2;

    // 遍历所有奇数
    for(int i = 3; i < MAX; i += 2)
    {
        if(!fset[i])
        {
            // 没有赋值过,则是质数,它的最小质因数就是自己
            fset[i] = i;

            // 处理这个质数的倍数
            for(int j = i + i; j < MAX; j += i)
            {
                // 如果没有赋值过,这说明当前质数,是这个数的最小质因数
                if(!fset[j])
                    fset[j] = i;
            }
        }
    }

    aset[0] = 0;
    aset[1] = 0;

    for(int i = 2; i < MAX; ++i)
        aset[i] = aset[i-1] + fset[i];

    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", aset[n]);
    }

    return 0;
}
