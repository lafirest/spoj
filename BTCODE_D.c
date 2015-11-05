// 开始把这道题目当作dp问题来做,然后发现做不出来,实际这是个
// 很巧妙的贪心问题
// 1.求出每个酒店每个时段的收入
// 2.对于每个酒店求出其各个时段的最大收入
// 3.累加各个酒店的最大收入
#include <stdio.h>

#define MAX 100
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define bigint long long int
bigint data[3][MAX][MAX];

int read(void)
{
    int n = 0;
    char p = getchar();
    while(p < '0')
        p = getchar();

    while(p >= '0')
    {
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar();
    }

    return n;
}

int main(void)
{
    int t = read();
    while(t--)
    {
        int m = read();
        int n = read();

        // 数据读取
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < m; ++j)
                for(int z = 0; z < n; ++z)
                    data[i][j][z] = read();

        // 算出各个酒店各个时段的收入
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
            {
                int minv = min(data[0][i][j], data[1][i][j]);
                data[2][i][j] *= minv;
            }

        bigint res = 0;
        for(int i = 0; i < m; ++i)
        {
            bigint maxv = 0;
            // 求出改酒店所有时段中的最大收入
            for(int j = 0; j < n; ++j)
                maxv = max(maxv, data[2][i][j]);

            res += maxv;
        }

        printf("%lld\n", res);
    }

    return 0;
}
