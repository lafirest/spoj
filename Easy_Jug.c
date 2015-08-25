#include <stdio.h>

int 
gcd(int a, int b)
{
    if(b == 0)
        return a;
    else 
        return gcd(b, a % b);
}

int
main(void)
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if(z > x && z > y)
            printf("NO\n");
        else if(z == x || z == y)
            printf("YES\n");
        else
        {
            int gcdv = gcd(x, y);
            if(z % gcdv)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }

    return 0;
}
