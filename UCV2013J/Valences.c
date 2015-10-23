#include <stdio.h>
#include <math.h>

// 这个会wrong answer.懒得去改了.这里的思路是算出树的高度,
// 然后算出离完全2叉树差了几个节点,然后就能算出从第几个数字
// 开始读去了。错误的原因是n要区分奇偶

int
main(void)
{
    while(1)
    {
        int n;
        int temp;
        int start;
        scanf("%d", &n);

        if(!n)
            break;

        if(n <= 2)
            start = 1;
        else
        {

            int high = log(n) / log(2) + 1;
            int total = pow(2, high) - 1;
            start = pow(2, high - 1);
            int miss = (total - start) / 2;
            start -= miss;
            start = n - start;
        }

        int i = 1;
        int sum = 0;

        for(; i <= start; ++i)
            scanf("%d", &temp);

        for(; i <= n; ++i)
        {
            scanf("%d", &temp);
            sum += temp;
        }

        printf("%d\n", sum);
    }

    return 0;
}
