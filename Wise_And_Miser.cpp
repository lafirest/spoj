#include<cstdio>
#include<iostream>
using namespace std;

#define INF 99999999

int min(int a, int b) {
    return a < b ? a : b;
}

/*
 * 这里的做法和递归版的刚好相反,根据递归的思路,每个位置的最优解取决
 * 于子状态的最优解.这里就是从底部开始选取最优解,逐渐往上构建,然后
 * 选取顶部最优的值,可以看作是递归开始依次返回时的操作
 */
int main() {
    int n,m;
    int g[101][101];
    int dp[101][101];
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {             scanf("%d", &g[i][j]);         }         if (i > 0) {
            for (int j = 0; j < m; ++j) {                 dp[i][j] = INF;                 if (j>0) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + g[i][j]);
            }
            if (j < m-1) {
                dp[i][j] = min(dp[i][j], dp[i-1][j+1] + g[i][j]);
            }
            dp[i][j] = min(dp[i][j], dp[i-1][j] + g[i][j]);
            }
        } else {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = g[i][j];
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < m; ++i) {
        ans = min(dp[n-1][i], ans);
    }
    printf("%d\n", ans);
    return 0;
}
