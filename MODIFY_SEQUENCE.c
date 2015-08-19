// 按照规则,进行暴力求解
#include <stdio.h>

int
main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, temp;
        int can = 1;
        int last = 0;   //当前需要减去的值
        scanf("%d", &n);
        if(n == 1)
        {
            // 一个数是没法进行减操作的,所以can = 0
            scanf("%d", &temp);
            can = 0;
        }
        else
        {
            int skip = 0;
            scanf("%d", &last);
            --n;

            while(n--)
            {
                scanf("%d", &temp);

                // 跳过判断,读取下个数据
                if(skip)
                {
                    skip = 0;
                    last = temp;
                    continue;
                }

                // 已经不能实现了,则后续就不判断了
                if(can)
                {
                    // 当前数据和上个相同,则下个数据直接读取,不做额外处理
                    if(last == temp)
                    {
                        skip = 1;

                        // 这里需要更新last,否则循环在这儿结束,且不更新last的值
                        // 则后面输出时的判断会出错
                        last = 0;   
                    }
                    else if(last == 0)
                        last = temp;    //前一个为0,则直接过
                    else if(last < temp)
                        last = temp - last; //前面剩下的值比当前值小,减去剩下的值,更新last
                    else
                        can = 0; //前面的值比当前的值大,按照规制没法实现
                }
            }
        }

        // 这里需要判断last(最后剩下的值)是否为0
        if(can && !last)
            printf("YES\n");
        else 
            printf("NO\n");
    }
    return 0;
}
