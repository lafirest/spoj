//https://github.com/saurabhhack123/SPOJ/blob/master/NFACTOR.cpp
//这个用的是动态规划,连素数筛选都美看到,一开始不太理解为什么counter就求出了
//质因数的个数...第一次看见这种算法
//版本2应该有bug,求的是质因数个数,而不是不同的质因数个数
//版本1则是求出所有的质因数,并且滤掉相同的
//这里的算法是:
//  1.遍历2之后的所有的偶数, 这些数都有一个质因数2, ++counter[i]
//  2.遍历所有奇数,如果counter[i]为0,则这个数是个质数,有一个质因数就是它自己,++counter
//  然后处理该质因数的所有倍数,它们都有一个共同的质因数i
//  3.遍历完所有数后,counter中记录的就是每个数拥有的不同的质因数个数
#include <stdio.h>

#define MAX 1000001 
int counter[MAX];
int dp[MAX][11];

void sieve(void) 
{
    int i, j;

    // 求出每个数的不同的质因数个数
    counter[2] = 1;

    // 遍历所有的偶数
    for(i = 4; i < MAX; i += 2) 
        ++counter[i];

    // 遍历所有的奇数
    for(i = 3; i < MAX; i += 2) 
    {
        if(!counter[i]) 
        {
            counter[i] = 1;

            // 处理该质数的倍数
            for(j = i<<1; j < MAX; j+=i) 
                ++counter[j];
        }
    }

    // dp
    for(i = 1; i < MAX; i++) 
    {
        for(j = 0; j < 11; j++) 
        {
            if(counter[i]==j) 
                dp[i][j] = dp[i-1][j] + 1;
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
}

int main() 
{
    int t, a, b, n;
    sieve();
    scanf("%d", &t);
    while(t--) 
    {
        scanf("%d %d %d", &a, &b, &n);
        printf("%d\n", dp[b][n] - dp[a-1][n]);
    }

    return 0;
}
