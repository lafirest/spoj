// 贪心算法,尽量将1/4和3/4匹配
// 这里是最直观的写发,1/2和1/2匹配,1/4和3/4匹配
// 然后在最后计算余下的数量
// 代码2使用的算法则是先统计所有r1_2,r1_4,r3_4,最后在计算,代码比较简洁
// 这里错了两次的原因是没有给r1_2,r1_4,r3_4赋初始值
#include <stdio.h>

int
main(void)
{
    int x,y=0;
    short times, r1_2=0, r1_4=0, r3_4=0, acc = 1;
    scanf("%d", &times);
    while(times--)
    {
        scanf("%d/%d", &x, &y);
        if(x==1)
        {
            if(y==2)
            {
                if(r1_2)
                {
                    --r1_2;
                    ++acc;
                }
                else
                    ++r1_2;
            }
            else 
            {
                if(r3_4)
                {
                    --r3_4;  
                    ++acc;
                }
                else
                    ++r1_4;
            }
        }
        else 
        {
            if(r1_4)
            {
                --r1_4;
                ++acc;
            }
            else
                ++r3_4;
        }
    }

    // 最后可能剩下的结果是:(1/2 1/4), (1/2 3/4), 1/2, 1/4, 3/4
    if(r1_2)
    {
        if(r1_4)
        {
            ++acc;
            r1_4 -= 2;
            if (r1_4 > 0)
            {
                if(r1_4 % 4)
                    acc += r1_4 / 4 + 1;
                else 
                    acc += r1_4 / 4;
            }
        }
        else if (r3_4)
            acc += 1 + r3_4;
        else 
            ++acc;
    }
    else if (r1_4)
    {
        if(r1_4 % 4)
            acc += r1_4 / 4 + 1;
        else
            acc += r1_4 / 4;
    }
    else if (r3_4)
        acc += r3_4;

    printf("%d\n", acc);
    return 0;
}
