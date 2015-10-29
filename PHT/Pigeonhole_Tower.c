//0.14s
#include <stdio.h>
#include <math.h>

#define binint long long int 

int main(void)
{
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i)
    {
        binint n;
        scanf("%lld", &n);
        binint r = sqrt(n + 1) - 1;
        printf("Case %d: %lld\n", i, r);
    }
   
    return 0;
}
