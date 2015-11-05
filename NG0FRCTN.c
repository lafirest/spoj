// 很巧妙的一道题目
#include <stdio.h>
#include <math.h>

#define bigint long long int

int main()
{
    while(1)
    {
        bigint num;
        scanf("%lld", &num);

        if(num == 0)
            break;

        bigint path[50];

        int n = 1;
        int d = 1;
        if(num != 1)
        {
            // 生成从num到1(根)的路径
            path[0] = num;
            int count = 1;

            while(1)            
            {
                path[count] = path[count - 1] / 2;
                if(path[count] == 1)
                    break;

                ++count;
            }      

            // 从根出发,按照规律,如果当前这个的位置是
            // 奇数则分子不变,分母加上分子
            // 是偶数则刚好相反,然后一直搜索到目标点
            for(int i = count - 1; i >= 0; --i)      
            {
                if(path[i] & 1) 
                    n += d;
                else   
                    d += n;
            }
        }

        printf("%d/%d\n", n, d);
    }

    return 0;
}
