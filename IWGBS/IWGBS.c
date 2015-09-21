// 当n=10000时,结果为2090位的数字,所以这儿需要用大数加法才行,所以这个版本不能ac
#include <stdio.h>
#define bigint long long int
#define MAX 10010

bigint dp[MAX][2];

int main(void)
{
    int n;
    scanf("%d", &n);
    dp[0][1] = 1;
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
    }
    printf("%lld\n", dp[n][0] + dp[n][1]);
    return 0;
}
