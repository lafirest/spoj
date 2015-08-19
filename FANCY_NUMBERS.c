// 观察能发现连续n个数有2^(n-1)个组合,所以遍历字符串,累乘组合数
// 就可以得到最终解,这道题比较简单
#include <stdio.h>
#include <math.h>

int
main(void)
{
    char buffer[64];
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", buffer);

        int value = 1;
        //优化: 这个默认值如果设置为0的话,就不用在pow时减1了
        int continuous = 1; 

        char last = *buffer;
        char* str = buffer + 1;
        char cur;

        while((cur =*str))
        {
            if(last == cur)
                ++continuous;
            else
            {
                value *= pow(2, continuous - 1);
                continuous = 1;
            }

            last = cur;
            ++str;
        }

        value *= pow(2, continuous - 1);

        printf("%d\n", value);
    }

    return 0;
}
