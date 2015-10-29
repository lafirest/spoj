// 和之前做过的浮点数二分查找类似,重点都是浮点数不能进行精确判断,只能通过范围判断
// 然后评论里面都说道了牛顿迭代法,但是我没看懂...这里和之前做过的不一样的地方就是
// 没有给出范围上限,所以要自己去确定上限,其次就是迭代次数.之前做过的都是不现在迭代
// 次数的,这里出于时间考虑,且评论里面说60次迭代就够了
#include <stdio.h>
#include <math.h>

int main(void)
{
    int t; 
    scanf("%d", &t);

    while(t--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        // 50次迭代,和2500的上限是从github上看到的
        double l =  0;
        double h = 2500; 
        double m, r;

        for(int i = 1; i <= 50; ++i)
        {
            m = (l + h) / 2;
            r = a * m + b * sin(m) - c;

            if(r < 0.000001 && r > -0.000001)
                break;

            if(r > 0)
                h = m;
            else
                l = m;
        }

        printf("%lf\n", m);
    }

    return 0;
}
