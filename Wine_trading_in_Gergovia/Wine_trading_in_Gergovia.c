// 简单的数学应用
#include <stdio.h>

#define bigint long long int
#define abs(x) (x > 0 ? x : -x)

int
main(void)
{
    int n;
    while(1)
    {
        scanf("%d", &n);
        if(!n)
            break;

        bigint units = 0;
        bigint acc = 0;
        int v = 0;
        
        while(n--)
        {
            units += abs(acc);
            scanf("%d", &v);
            acc += v;
        }

        printf("%lld\n", units);
    }

    return 0;
}
