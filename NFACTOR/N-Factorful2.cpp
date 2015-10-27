// 这里是版本2,版本1被覆盖了,懒得去spoj上拷贝了,版本1的做法是:通过筛法
// 求出素数,并记录合数的组成方式,然后求出每个数有多少个不同的质因数,
// 之后按照数量依次放入对应的数组中,查询时用二分查找下限和上限,然后两个
// 相减就是结果了.然后超时了.
// 版本二是在github上看到的,用的是试除法,而且用的是范围线性查找,理论上效率
// 应该比版本1低很多,但是我还以为可以ac,就写了份,然后没有还是超时,github上
// 原有的代码也是超时...坑
#include <cstdio>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 1000010
#define SEQ 1001

bool prime[MAX];

int main(void)
{

    for(int i = 2; i < SEQ; ++i)
    {
        if(prime[i])
            continue;

        for(int j = i * i; j <= MAX; j += i)
            prime[j] = true;
    }
    prime[0] = true;
    prime[1] = true;

    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a, b, n;
        int num = 0;
        scanf("%d %d %d", &a, &b, &n);
        int an = a + n;

        if(n == 0)
        {
            if(a == 1)
                num = 1;
            else 
                num = 0;
        }
        else if(n == 1)
        {
            for(int i = a; i <= b; ++i)
            {
                if(!prime[i])
                    ++num;
            }
        }
        else if(n > 7)
            num = 0;
        else
        {
            int base[7]={2,3,5,7,11,13,17};
            int start = 1;
            for(int i = 0; i < n; ++i)
                start *= base[i];

            start = max(start, a);

            for(int i = start; i <= b; ++i)
            {
                int factors = 0;
                int cur = i;
                for(int j = 2; j <= cur && factors <= n; ++j)
                {
                    if(!prime[j] && cur % j == 0)
                    {
                        ++factors;
                        cur /= j;
                    }
                }

                if(factors == n)
                    ++num;
            }
        }

        printf("%d\n", num);
    }

    return 0;
}
