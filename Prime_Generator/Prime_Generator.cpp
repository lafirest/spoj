#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d\n", &t);
    while(t--)
    {
        int n,m;
        scanf("%d %d\n", &n, &m);
        int * primes = new int[m-n+1];  
        for(int i=0;i<m-n+1;++i)
            primes[i] = 0;      //全部初始为0(用memset也行),然后筛选掉合数

        for(int p=2;p*p<=m;++p)
        {
            int less = n / p;
            less *= p;    // first number <= N && p divides N

            //找到最接近n的p的倍数,累加p，依次将p的后续倍数标记为合数
            for(int j=less;j<=m;j+=p) 
                if(j != p && j >= n)
                {
                    printf("%d,%d\n", j, j - n);
                    primes[j - n] = 1;
                }
        }

        for(int i=0;i<m-n+1;++i)
        {
            //1不是合数也不是素数
            if(primes[i] == 0 && n+i != 1) //输出除去数字"1" 
                printf("%d\n",n+i);
        }

        printf("\n");

        delete [] primes;
    }
}
