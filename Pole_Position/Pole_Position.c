#include <stdio.h>

#define MAX 1001
short arr[MAX];

int main(void)
{
    int n;
    while(1)
    {
        scanf("%d", &n);
        if(!n)
            break;

        int suc = 1;
        int num, inc;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d %d", &num, &inc);
            if(suc)
            {
                int rpos = i + inc;
                if(rpos < 1 || rpos > n || arr[rpos])
                    suc = 0;
                else 
                    arr[rpos] = num;
            }
        }

        if(suc)
        {
            for(int i = 1; i <= n - 1; ++i)
                printf("%d ", arr[i]);

            printf("%d\n", arr[n]);
        }
        else
            printf("-1\n");

        for(int i = 1; i <= n; ++i)
            arr[i] = 0;
    }

    return 0;
}
