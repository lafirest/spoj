// 正多边形边长公式:L=2Rsin(π/n）
// 但这道题ac时用的公式是:R = L / (2 * sin(π / 2n))
// 然后这道题目中的n是指小圆的个数,2n才是多边形的边数!!!
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979

int 
main(void)
{
    int r, n;
    while(EOF != scanf("%d %d", &r, &n))
    {
        if(r + n == 0)
            break;

        double R = r / sin(PI / 2 / n);
        printf("%.2f\n", R);
    }
}
