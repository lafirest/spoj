// 这是我在spoj上ac的第100道题目,但是这代码不是我写的!!!,真是失望.
// 这是一道dp题目,我一直找不到转移公式
// http://www.quora.com/Can-some-one-explain-how-to-solve-square-brackets-problem-on-spoj-SPOJ-SQRBR
// 上面是解释,以后有心情慢慢看
#include <stdio.h>
#include <string.h>
#define MAX 500

int dp[MAX][MAX], n, k;
int open[MAX];

int main()
{
    int t, d;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        memset(dp, 0, sizeof(dp));
        memset(open, 0, sizeof(open));
        dp[0][0] = 1;

        for(int i = 1; i <= k; i++)
        {
            scanf("%d", &d);
            open[d] = 1;
        }

        for(int i = 1; i <= 2 * n; i++)
        {
            for(int j = 0; j <= 2 * n; j++)
            {
                if(open[i])
                {   
                    if(j != 0)
                        dp[i][j] = dp[i-1][j-1];
                    else
                        dp[i][j] =  0;
                }
                else
                {
                    if(j != 0)
                        dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
                    else
                        dp[i][j] = dp[i-1][j+1];
                }
            }
        }
        printf("%d\n", dp[2*n][0]);
    }

    return 0;
}
