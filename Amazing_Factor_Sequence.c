#include <stdio.h>

#define MAX 1000010
#define bigint long long int
bigint sset[MAX];
bigint aset[MAX];

int main(void)
{
    // 这里用之前求一个数有多少个不同的质因数的算法
    // 从底构造小于某个数的因数的和
    for(int i = 2; i < MAX; ++i)
    {
        for(int j = i + i; j < MAX; j += i)
           sset[j] += i; 
    }

    // 按照公式构造序列
    aset[0] = 0;
    aset[1] = 0;
    for(int i = 2; i < MAX; ++i)
        aset[i] = aset[i - 1] + sset[i] + 1; // 所有数都能整除1,所以上面是没有处理1,而是放在这里处理

    int t;
    scanf("%d", &t);

    while(t--)
    {
        bigint n;
        scanf("%lld", &n);
        printf("%lld\n", aset[n]);
    }

    return 0;
}
