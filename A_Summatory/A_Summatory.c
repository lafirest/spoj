#include <stdio.h>
#define lint long long 

lint array[1000001];

int
main(void)
{
    array[1] = 1;
    lint acc = 1;
    lint y = 3;
    int z = 3;
    int i, n;
    for(i = 2; i < 1000001; ++i)
    {
        acc += y * y;

        if(acc >= 1000000003)
            acc %= 1000000003;

        // y的值也会膨胀的很大,需要求余
        if(y >= 1000000003)
            y %= 1000000003;

        array[i] = acc;
        y += z;
        ++z;
    }

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &i);
        printf("%lld\n", array[i]);
    }
    return 0;
}
