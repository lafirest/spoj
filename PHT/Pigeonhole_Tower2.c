//0.14s
#include <stdio.h>
#include <math.h>

#define binint long long int 

binint fastio(void)
{
    binint n = 0;
    int s = 1;

    char p = getchar();

    // 读取空白等
    while(p < '0')
        p = getchar( );

    // 生成数字
    while(p >= '0') 
    {
        // n = n * 10 + (p - '0')
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar( );
    }

    return n * s;
}

int main(void)
{
    binint t = fastio();
    for(int i = 1; i <= t; ++i)
    {
        binint n = fastio();
        binint r = sqrt(n + 1) - 1;
        printf("Case %d: %lld\n", i, r);
    }
   
    return 0;
}
