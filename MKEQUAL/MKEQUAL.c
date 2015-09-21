#include <stdio.h>

int
main(void)
{
    int t,sum,n,temp;
    scanf("%d",&t);

    while(t--)
    {
        sum = 0;
        scanf("%d", &n);

        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &temp);
            sum += temp;
        }

        if(sum % n == 0)
            printf("%d\n", n);
        else
            printf("%d\n", n-1);
    }

    return 0;
}
