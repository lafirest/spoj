#include <stdio.h>

int 
main(void)
{
    while(1)
    {
        int n;
        scanf("%d", &n);
        if(!n)
            break;

        int m = 0;
        if(n & 1)
            m = (n + 1) / 2;
        else
            m = n / 2;

        int s = n - m;

        int i = 1;
        int temp;
        for(; i <= s; ++i)
            scanf("%d", &temp);

        int sum = 0;
        for(; i <= n; ++i)
        {
            scanf("%d", &temp);
            sum += temp;
        }

        printf("%d\n", sum);
    }

    return 0;
}
