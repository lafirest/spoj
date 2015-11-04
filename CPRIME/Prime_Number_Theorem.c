// tle
// 主要是因为1亿个int占用的内存太大,花费在内存寻址上的时间很多
// 而且筛法还没有优化
#include <stdio.h>
#include <math.h>

#define MAX 100000001
#define SEQ 10001

int prime[MAX];

int read(void)
{
    int n = 0;
    char p = getchar();
    while(p < '0')
        p = getchar();

    while(p >= '0')
    {
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar();
    }

    return n;
}

int main(void)
{
    for(int i = 2; i <= SEQ; ++i)
    {
        if(prime[i])
            continue;

        for(int j = i + i; j < MAX; j += i)
            prime[j] = 1;
    }

    int counter = 0;
    for(int i = 2; i < MAX; ++i)
    {
        if(prime[i])
            prime[i] = counter;
        else
        {
            ++counter;
            prime[i] = counter;
        }
    }

    while(1)
    {
        int x = read();
        if(!x)
            break;
        
        int px = prime[x];
        double r = fabs(px - x/log(x)) / px * 100.0;
        printf("%.1lf\n", r);
    }

    return 0;
}
