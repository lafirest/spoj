// 整除性判断,
// 252的因式分解为:4 9 7
// 525的因式分解为:3 25 7
// 一个数能够被252整除的充要条件是能同时被4、9、7整除,525也一样.
// 其中都有7,然后3、9的判断方式一样,4、25的判断方式一样,所以每个数只需要判断3种情况即可
// http://blog.yzjy.com.cn/yzzxh/archives/291858.aspx
// http://blog.sina.com.cn/s/blog_668e6e9d0100m6d5.html
// 因为数字很大,所以对于7的判断使用的是逐位求和法
#include <stdio.h>

#define MAX 50010
char buffer[MAX];
char* result[2] = {"No", "Yes"};
char ratio[6] = {1,3,2,-1,-3,-2};

int
main(void)
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%s", buffer);
        int len = 0;
        int sum = 0;
        char* str = buffer;
        char c;

        while((c = buffer[len]))
        {

            sum += c - '0';
            ++len;
        }

        if(len < 3)
            printf("No No\n");
        else 
        {
            int r252 = 1;
            int r525 = 1;

            if(sum % 9)
                r252 = 0;

            if(sum % 3)
                r525 = 0;

            if(r252 + r525 == 0)
                printf("No No\n");
            else
            {
                sum = 0;
                for(int i = len - 1, j = 0; i >= 0; --i)
                {
                    int v = buffer[i] - '0';
                    sum += v * ratio[j];
                    ++j;
                    if(j == 6)
                        j = 0;
                }

                if(sum % 7)
                    printf("No No\n");
                else
                {
                    sum = (buffer[len-2] - '0') * 10 + (buffer[len-1] - '0');
                    if(sum % 4)
                        r252 = 0;

                    if(sum % 25)
                        r525 = 0;

                    printf("%s %s\n", result[r252], result[r525]);
                }
            }
        }

    }

    return 0;
}
