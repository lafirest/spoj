// 题目比较简单,只需要注意字符串格式就可以了.这里的字符串处理写的很随意...
// 不是太好，但够用.还有就是用double而不是float来记录数据
#include <stdio.h>
#include <math.h>
#include <float.h>

double read_first(int* succ)
{
    double r;
    char p = getchar();
    while(p != '(')
    {
        if(p == EOF)
        {
            *succ = 0;
            return FLT_MIN;
        }
        p = getchar();
    }

    scanf("%lf", &r);

    *succ = 1;
    return r;
}

double read_second(void)
{
    double r;
    char p = getchar();
    while(p != ',')
        p = getchar();

    scanf("%lf", &r);

    return r;
}


int main(void)
{
    double lx, ly, cx, cy;
    double total = 0;
    int succ = 0;
    lx = read_first(&succ);
    ly = read_second();

    while(1)
    {
        succ = 0;
        cx = read_first(&succ);
        if(!succ)
            break;
        cy = read_second();
        double r = sqrt((cx - lx) * (cx - lx) + (cy - ly)  * (cy - ly)); 
        if(r < 0)
            r = -r;

        total += r;
        lx = cx;
        ly = cy;
        printf("The salesman has traveled a total of %.3lf kilometers.\n", total);
    }

    return 0;
}
