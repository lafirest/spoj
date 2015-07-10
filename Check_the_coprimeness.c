// 注意数据的类型应该是long long int，不然会溢出
// 虽然数据很大(10^12),但是这道题目直接使用暴力求解即可,不要想太复杂了
#include <stdio.h>

long long int gcd(long long int a, long long int b)
{
    if(!b)
        return a;

    return gcd(b, a % b);
}

int main(void)
{
    int t, i, f;
    long long int n, h;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &n);
        h = n >> 1;
        f = 1;
        while(h)
        {
            if(gcd(h, n) == 1)
            {
                f = 0;
                printf("%lld\n", h);
                break;
            }
            --h;
        }

        if(f)
            printf("1\n");
    }

    return 0;
}
