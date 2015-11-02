// 这里使用自底向上构造的筛法.所有非square free数记录自己因数中最大的
// square free数,而所有square free数不记录任何值.
// 读入一个输入后,变用sf中记录的最大square free数进行因式分解,如果sf[n]
// 则说明当前这个数是square free数,++r,然后直接退出即可
#include <stdio.h>

#define MAX 1000001

int sf[MAX];

int fastio(void)
{
    int n = 0;
    char p = getchar();

    // 读取空白等
    while(p < '0')
        p = getchar( );

    // 生成数字
    while(p >= '0') 
    {
        // n = n * 10 + (p - '0')
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar( );
    }

    return n;
}


int main(void)
{
    // 筛选square free数
    for(int i = 2; i < 1001; ++i)
    {
        // 如果是非square free数,则其任意倍数都是非square free数
        if(sf[i])
            continue;

        // 标记square free数i的所有倍数的当前最大square free因数为自己
        // 因为i从小到大,所以循环结束后,sf[j]中保存的是范围内最大的square free因数
        int square = i * i;
        for(int j = square; j < MAX; j += square)
            sf[j] = i;
    }

    int t = fastio();
    while(t--)
    {
        int n = fastio();
        int r = 0;

        // 因数分解
        while(n > 1)
        {
            // 分解为1个square free数了
            if(!sf[n])
            {
                ++r;
                break;
            }

            n /= sf[n];
            ++r;
        }

        printf("%d\n", r);
    }

    return 0;
}
