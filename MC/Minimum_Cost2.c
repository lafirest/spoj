// 不使用递归,而是用lcs算法来做的版本,0.03s
#include <stdio.h>

#define MAX 1010
#define max(a, b) (a > b ? a : b)
char strs[MAX];
char strt[MAX];
int dp[MAX][MAX];
int slen;
int tlen;

// 读取字符串
int read(char *str, int *len)
{
    char p = getchar();
    int n = 0;
    while(p < '#')
        p = getchar();

    if(p == '#')
        return 0;

    while(p > '#')
    {
        *str = p;
        ++str;
        p = getchar();
        ++n;
    }

    *len = n;

    return 1;
}

int lcs(void)
{
    for(int i = 0; i <= slen; ++i)
        for(int j = 0; j <= tlen; ++j)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(strs[i - 1] == strt[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    return dp[slen][tlen];
}

int main(void)
{
    while(1)
    {
        slen = 0;
        tlen = 0;
        if(!read(strs, &slen))
            break;

        read(strt, &tlen);
        int r = lcs();  // 计算lcs
        r = (slen - r) * 15 + (tlen - r) * 30; // 计算去掉lcs后的cost
        printf("%d\n", r);
    }

    return 0;
}
