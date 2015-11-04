// 0.79s
// 这里用c++的bitset来进行筛选,然后优化了筛法算法,之后将素数存入数组中
// 每次在读取输入后,在数组中查找第一个小于等于输入的数的位置
#include <cstdio>
#include <cmath>
#include <bitset>
using namespace std;

#define MAX 100000001
#define SEQ 10001
#define SMAX 5761460

bitset<MAX> prime;
int primes[SMAX];
int len;

int read(void)
{
    int n = 0;
    char p = getchar();
    while(p < '0')
        p = getchar();

    while(p >= '0')
    {
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar();
    }

    return n;
}

int find(int x)
{
    if(x <= 2)
        return 1;

    if(x >= primes[len])
        return len;

    int low = 1;
    int high = len;
    while(low < high)
    {
        int mid = low + (high - low + 1) / 2;
        if(primes[mid] == x)
            return mid;
        else if(primes[mid] < x)
            low = mid;
        else 
            high = mid - 1;
    }

    return low;
}

int main(void)
{
    // 和版本1相比筛法优化的地方:
    // 1.2是唯一一个偶质数,也就是说除了2,其他偶数都是合数,而这里的筛选
    // 只关心哪些数是素数,而不关心诸如因子这些东西,因此这里可以跳过所有偶数
    // 只处理奇数
    for(int i = 3; i <= SEQ; i += 2)
    {
        if(prime[i])
            continue;

        // 2.将j = i + i改为j = i * i,避免重复判断
        for(int j = i * i; j < MAX; j += i)
            prime[j] = 1;
    }

    primes[1] = 2;
    len = 2;

    // 收集素数
    for(int i = 3; i < MAX; i += 2)
    {
        if(!prime[i])
        {
            primes[len] = i;
            ++len;
        }
    }
    --len;

    while(1)
    {
        int x = read();
        if(!x)
            break;

        int px = find(x);

        double r = fabs(px - x/log(x)) / px * 100.0;
        printf("%.1lf\n", r);
    }

    return 0;
}
