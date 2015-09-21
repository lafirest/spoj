// http://mathworld.wolfram.com/SteinmetzSolid.html
// 纯数学题,使用公式可以直接得到解,注意数据类型需要时double
#include <stdio.h>
#include <math.h>

int 
main(void)
{
    int t;
    scanf("%d", &t);

    double cst = 8 * (2 - sqrt(2));
    while(t--)
    {
        int r;
        scanf("%d", &r); 
        printf("%.4lf\n", cst * pow(r, 3));
    }

    return 0;
}
