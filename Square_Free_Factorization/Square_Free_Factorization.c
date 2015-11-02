// tle
// 这里的思路是筛选出所有square free的数字,然后放入sfs集合中
// 每次输入一个数字后,用二分查找找到离这个数最近的square free数
// 然后用试除法进行因式分解
//
// 这里的思路有问题:
// 1.从sf里面读取square free数字的耗时O(n),n为100万,这个数字很大
// 2.每次的输入都要进行一次二分查找,有1000次输入,每次二分最坏查找
// 19次左右,共需要查找19000次,数据也很大
// 3.如果查找的数字不是输入数字的因数,则退化为线性查找,耗时O(n)
// 4.空间复杂度也很高
//
// 版本2用的是自底构造的筛法能在0.0s内ac
#include <stdio.h>

#define MAX 1000001

char sf[MAX];
int sfs[MAX];
int len = 0;

int fastio(void)
{
    int n = 0;
    char p = getchar();

    // 读取空白等
    while(p < '0')
        p = getchar( );

    // 生成数字
    while(p >= '0') 
    {
        // n = n * 10 + (p - '0')
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar( );
    }

    return n;
}

int find(int i)
{
    int low = 1;
    int high = i;
    if(high > len)
        high = len;

    while(low < high)
    {
        int mid = low + (high - low + 1) / 2;
        //  printf("---> %d %d %d\n", low, mid, high);

        if(sfs[mid] == i)
            return mid;
        else if(sfs[mid] < i)
            low = mid;
        else 
            high = mid - 1;
    }

    return low;
}

int main(void)
{
    for(int i = 2; i < 1001; ++i)
    {
        if(sf[i])
            continue; 

        int square = i * i;
        for(int j = square; j < MAX; j += square)
            sf[j] = 1;
    }

    for(int i = 0; i < MAX; ++i)
    {
        if(sf[i])
            continue;

        sfs[len] = i;
        ++len;
    }
    --len;

    int t = fastio();
    while(t--)
    {
        int n = fastio();
        int r = 0;

        while(n)
        {
            int k = find(n);
            while(k >= 0)
            {
                if(n % sfs[k] == 0)
                {
                    ++r;
                    n /= sfs[k];
                    break;
                }

                --k;
            }

            if(k < 0)
                break;
        }

        printf("%d\n", r);
    }

    return 0;
}
