#include<stdio.h>
#include<math.h>

unsigned euler(unsigned x)
{
    unsigned i, res=x;
    for (i = 2; i < (int)sqrt(x * 1.0) + 1; ++i)
        if(x%i==0) 
        {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i; // 保证i一定是素数
        }
    if (x > 1) res = res / x * (x - 1);
    return res;
}

void 
main(void)
{
    int t = 0;
    int d =0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &d);
        printf("%d\n", euler(d));
    }
}
