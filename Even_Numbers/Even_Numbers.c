// 比较简单的一道题目循环移位即可
#include <stdio.h>

int main(void)
{
    int t,n,v;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(n & 1)
            printf("%d\n", n);
        else
        {
            v = 0;
            n >>= 1;
            int find = 0;
            while(n > 0)
            {
                if(n & 1)
                {
                    v <<= 1;
                    v |= 1;
                    find = 1;
                }
                else if(find)
                    v <<= 1;

                n >>= 1;
            }

            printf("%d\n", v);
        }
    }

}
