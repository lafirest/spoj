// 重点是最后显示的结果,开始一直用mid,导致了许多wa
#include<stdio.h>

#define bigint long long int
int trees[1000010];

int 
main(void)
{
    bigint n, m;
    scanf("%lld %lld", &n, &m);

    bigint right = 0;
    bigint left = 0;
    for(int i = 0; i < n; ++i)
    {
        int temp;
        scanf("%d", &temp);

        if(temp > right)
            right = temp;

        trees[i] = temp;
    }

    bigint mid = 0;
    bigint maxh = 0;
    while(left <= right)
    {
        mid = (left + right) / 2;

        // check(判断能否满足条件)
        bigint sum = 0;
        for(int i = 0; i < n; ++i)
        {
            if(trees[i] > mid)
                sum += trees[i] - mid;

            if(sum > m)
                break;
        }

        if(sum == m)		
        {
            // mid为长度时刚好满足,则返回
            maxh = mid;
            break;
        }
        else if(sum > m)
        {
            left = mid + 1;

            // 存下当前的mid
            if(mid > maxh)
                maxh = mid;
        }
        else 
            right = mid - 1;
    }

    // 不能用mid的原因是,当某次搜索不满足check时,修改right,之后有可能left多次小于right,导致多次
    // 搜索,但mid都不满足条件了,当最后结束时(left > right),此时的left mid right都和正确答案没有任何关系
    // 所以需要自己记录每次满足条件时的高
    printf("%lld\n", maxh);

    return 0;
}
