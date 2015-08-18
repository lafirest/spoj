// 区间更新问题,用线段树和BIT都行,但线段树的效率没有BIT高,且评论里面有用
// 线段树超时的,所以这儿用BIT来做,评论里面有用O(n)实现的,不知道用的是什么方法
#include <stdio.h>
#include <memory.h>
#define lowbit(x) (x & (x ^ (x - 1)))

long long int bit[10010];

int
main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, u;
        scanf("%d %d", &n, &u);
        memset(bit, 0, (n + 1) * sizeof(long long int));
        while(u--)
        {
            int l, r, v;
            scanf("%d %d %d", &l, &r, &v);

            // 题目里的下标从0开始,需要转换为以1开始
            int pos = l + 1;

            // 从起点开始向上开始更新整个树
            while(pos <= n)
            {
                bit[pos] += v;
                pos += lowbit(pos);
            }

            // 从范围后的第一个点开始减去刚刚加上的数
            // 这样保证更新的范围是l~r(不能用pos <= r + 1来进行
            // 更新,否则结果是错的,还不清除什么原因,估计是临界情况导致的)
            pos = r + 2; // r + 1 +1
            while(pos <= n)
            {
                bit[pos] -= v;
                pos += lowbit(pos);
            }
        }

        int q;
        scanf("%d", &q);
        while(q--)
        {
            int p;
            scanf("%d", &p);
            ++p;
            long long int value = 0;
            // 求所有增加了的值的和
            while(p > 0)
            {
                value += bit[p];
                p -= lowbit(p);
            }
            printf("%lld\n", value);
        }
    }

    return 0;
}
