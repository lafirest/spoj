#include <stdio.h>
#include <string.h>

static short dp[3001][3001] = {0};
#define min(a, b)  (a) < (b) ? (a) : (b)

short
lev(char* x, char* y)
{
    int i,j,diff = 0;
    short lenx = 1 + strlen(x);
    short leny = 1 + strlen(y);

    for(i = 1; i < lenx; ++i)
        dp[i][0] = i;

    for(j = 1; j < leny; ++j)
        dp[0][j] = j;

        for(i = 1; i < lenx; ++i)
    for(j = 1; j < leny; ++j)
        {
            diff = 1; 
            if (x[i - 1] == y[j - 1])
                diff = 0;
            
            dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + diff);
        }

    return dp[lenx - 1][leny - 1 ];
}

int 
main(void)
{
    char x[3001];
    char y[3001];
    int times = 0;
    scanf("%d", &times);
    getchar();
    while(times--)
    { 
        gets(x); 
        gets(y);
        printf("%d\n", lev(x, y));
    }
    return 0;
}
