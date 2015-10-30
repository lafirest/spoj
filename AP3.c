// 解一元二次方程.已经忘记怎么解了.高中的数学知识...
// https://github.com/pratyakshs/spoj/blob/master/AP3/AP3.cpp
// http://stackoverflow.com/questions/24456393/getting-wrong-answer-in-spoj-ap3-ap-complete-the-series
// https://github.com/Ouditchya/SPOJ/blob/master/AP3.cpp
#include <stdio.h>
#include <math.h>

#define bigint long long int

bigint fastio(void)
{
    bigint n = 0;
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

    return n;
}

int main(void)
{
    bigint t = fastio();

    while(t--)
    {
        bigint t3 = fastio();
        bigint t4 = fastio();
        bigint sum = fastio();
        bigint n;

        double a = t3 + t4; 
        double b = 7 * t3 + 5 * t4 + 2 * sum; 
        double c = 12 * sum;
        double n1 = (b + sqrtl(b * b - 4 * a * c)) / (2 * a);
        double n2 = (b - sqrtl(b * b - 4 * a * c)) / (2 * a);

        if(ceil(n1) == floor(n1))
            n = (llrintl)(n1);
        else
            n = (llrintl)(n2);
    
        bigint d =(t4 - t3) / (n - 6);
        bigint t1 = t3 - 2 * d;

        printf("%lld\n", n);

        for(int i = 0; i < n; ++i)
        {
            printf("%lld ", t1);
            t1 += d;
        }

        putchar('\n');
    }

    return 0;
}
