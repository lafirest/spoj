// 记得初始化变量
#include <stdio.h>

#define max(a,b) (a) > (b) ? (a) : (b)

int
main(void)
{
    int times, x, y, r1_2=0, r1_4=0, r3_4=0, acc=1;
    scanf("%d\n", &times);
    // 先统计所有的输入
    while(times--)
    {
        scanf("%d/%d", &x, &y);
        if(x==1)
        {
            if(y==2)
                ++r1_2;
            else
                ++r1_4;
        }
        else 
            ++r3_4;
    }

    // 3/4只能占一份
    acc += r3_4;

    // 将1/4和3/4匹配
    r1_4 = max(0, r1_4 - r3_4);

    // 将1/2和1/2匹配
    acc += r1_2 / 2;
    if (r1_2 % 2)
    {
        // 有剩下的则可以提供两个1/4
        ++acc;
        r1_4 = max(0, r1_4 - 2);
    }

    // 计算1/4需要的个数
    acc += r1_4 / 4;
    if (r1_4 % 4)
        ++acc;

    printf("%d\n", acc);
    return 0;
}
