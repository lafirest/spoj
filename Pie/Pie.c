//这个版本改进了lisp版本的问题,然后ac了
#include <stdio.h>
#define MAX 10001
#define PI 3.14159265358979323846264338327950 
#define size(x) (PI * x * x)

double array[MAX];

int 
main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, f, r; 
        double sum;
        scanf("%d %d", &n, &f);
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &r);
            double s = size(r);
            array[i] = s;
            sum += s;
        }

        ++f;
        double s = 0;
        double e = sum / f;

        //while(e > s + 0.0000000001)
        while(e > s + 0.00001)
        {
            double mid = (s + e) / 2;

            int pieces = 0;
            int small = 0;

            // check,判断下次搜索的方向
            for(int i = 0; i < n; ++i)
            {
                pieces += array[i] / mid;
                if(pieces >= f)
                {
                    small = 1;
                    break;
                }
            }

            if(small)
                s = mid;
            else
                e = mid;
        }

        printf("%.4lf\n", s);
    }
}
