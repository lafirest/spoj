// 指数问题,难点是看懂题目
#include <stdio.h>
#include <math.h>

int 
main(void)
{
    int n;
    double tmp,p0,p1,t,p;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%lf %lf %lf %lf", &p0, &p1, &t, &p);
        tmp = log(p1 / p0) / t; //t秒从p0增加到p1,求出指数
        printf("Scenario #%d: %.2lf\n", i, log(p / p0) / tmp); // 通过每秒增加的倍数求出需要的秒数
    }
    return 0;
}
