// 这里的想法很朴素,就是哪个时间段有人则这个时间段都加1
// 然后只需要求出整个数组中最大的值即可,但开始用memset会超时
// 后面就改成了这在tag写法,但是却得到了WA
#include <stdio.h>
#include <memory.h>
//#include <vector>
//using namespace std;

unsigned int state[10000001];
bool tag = 1;

int main(void)
{
    int t, n, i, j, x, y;
    scanf("%d", &t);
    while(t--)
    {
        unsigned int max = 0;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d %d", &x, &y);
            for(i = x; i <= y; ++i)
            {
                unsigned int& value = state[i];
                if((value & 1) == tag)
                    value = 0;
                
                value |= !tag;
                value += 2; 

                if(value > max)
                    max = value;
            }
        }

        tag = !tag;

        printf("%d\n", max >> 1);
    }
}
