// https://en.wikipedia.org/wiki/Stirling's_approximation N!的近似解
// e 的相关介绍
// pi 的相关介绍
// http://mathworld.wolfram.com/NumberLength.html 求数长度的公式
// http://baike.baidu.com/link?url=DWklXlcaogPWfqAfZe-rvjJmDkx0THwY4vr9ylThQLCrEqEcYKFm0OZS8mhLb11OZDdO-mxd7Wcmw-FRYJAsgK 对数运算公式
#include <stdio.h>
#include <math.h>

#define pi 3.1415926535898 
#define e 2.718281828459 
//#define len(x) ((long long)(log10((x))+1))
//#define stirling(x) (sqrt(2 * pi * (x)) * pow(n / e, (x)))
//#define len(x) ((0.5 * log10(2 * pi * (x)) + (x) * log10((x) / e)) + 1)

int main(void)
{
    int t;
    long long int l;
    double n;
   // long long t,n,l;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf", &n);
        if(n == 0.0 || n == 1.0)
            printf("1\n");
        else
        {
            //l = len(n); 
            //l = 0.5 * log10(2.0 * pi * n) + n * log10(n / e) + 1;
            // 真心无语了,用上面的log10求出来的结果和下面是一样的,但一直不能ac,估计是除以e时精度丢失了.
            l=(((log(2.00*pi*n)/2.00)+(n*(log(n)-1.00)))/log(10.0))+1;
            printf("%lld\n",l);
        }
    }

    return 0;  
}
