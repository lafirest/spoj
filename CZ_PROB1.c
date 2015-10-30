// 这个应该算是到计数dp吧.死活找不到转移方程,哈哈...
// 转移方程从github上扒下来的.看了才发现转移方程这么简单
// https://github.com/kanirudh/spoj/blob/master/cz_prob1.cpp
#include <stdio.h>

#define PMAX 8000
#define PSEQ 91
int prime[PMAX];
int sersies[PMAX];
int dp[4][PMAX];

int main(void)
{
    // 素数筛选
    for(int i = 2; i < PSEQ; ++i)
    {
        if(prime[i])
            continue;

        for(int j = i + i; j < PMAX; j += i)
            prime[j] = 1;
    }

    // 筛选符合条件的,这个循环可以和下面的循环合并
    for(int i = 1; i < PSEQ; ++i)
    {
        int ii = i * i;
        for(int j = 2; j < PSEQ; ++j)
        {
            int jj = j * j;
            int sq = ii + jj;
            if(sq < PMAX)
            {
                if(prime[sq] != 1)
                    prime[sq] = 2;
            }
        }

    }

    // 收集符合条件的
    sersies[1] = 2;
    int j = 2;
    for(int i = 1; i < PMAX; ++i)
    {
        if(prime[i] == 2)
        {
            sersies[j] = i;
            ++j;
        }
    }

    // dp初始化
    for(int i = 0; i < PMAX; ++i)
        dp[1][i] = 1;

    for(int i = 2; i <= 3; ++i)
    {
        dp[i][0] = 1;
        dp[i][1] = 1;
    }

    // 构造dp
    for(int j = 2; j < PMAX; ++j)
        for(int i = 2; i <= 3; ++i)
        {
            dp[i][j] = 0;
            for(int k = 1; k <= i; ++k)
                dp[i][j] += dp[k][j-k];

            // dp[i][j] = sum(dp[1][j-1] + dp[2][j-2] .... dp[k][j-k])
        }

    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k, p;
        scanf("%d %d", &n, &k);
        p = sersies[n];

        printf("%d\n", dp[k][p]);
    }

    return 0;
}
