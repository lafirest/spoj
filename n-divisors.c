// 很好的题目.筛法+试除法
// 求一个数的因数个数,可以先求出这个数的质因数分解形式,然后根据d(n)公式求出因数个数
// 因为范围是从1~10亿,如果单纯使用筛法,光筛选就要消耗大量时间.这里a和b直接的距离是1w,
// 远远小于1~10亿的距离.因此这里的做法是筛选出1~sqrt(10亿)间的素数,然后对a~b间的数使用
// 试除法求出因数个数,进行统计
// d(n)相关内容:http://mathworld.wolfram.com/DivisorFunction.html
#include <stdio.h>

#define MAX 31684
#define SMAX 178
char check[MAX];
int prime[MAX];

int main(void)
{
    // 除2外的所有偶数都是合数,不需要判断
    for(int i = 3; i <= SMAX; i += 2)
    {
        if(check[i])
            continue;

        for(int j = i * i; j < MAX; j += i)
            check[j] = 1;
    }

    // 收集素数
    prime[0] = 2;
    for(int i = 3, j = 1; i < MAX; i += 2)
    {
        if(check[i])
            continue;

        prime[j] = i;
        ++j;
    }

    int a, b, n;
    int r = 0;
    scanf("%d %d %d", &a, &b, &n);

    for(int i = a; i <= b; ++i)
    {
        int iv = i;
        int c = 1;
        int p = 0;

        // 求质因数,并求出合数
        for(int j = prime[p]; j * j <= iv; ++p, j = prime[p])
        {
            int pc = 0;
            while(iv % j == 0)
            {
                iv /= j;
                ++pc;
            }

            c *= pc + 1;
        }

        if(iv != 1)
            c *= 2;

        if(c == n)
            ++r;
    }

    printf("%d\n", r);

    return 0;
}
