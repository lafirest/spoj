// 贪心 + 排列组合,从小到大排序,比如5 8,第一把刀有5种选择
// 第2把刀则是(8-1)7种选择,因此共有35种选择
#include <cstdio>
#include <algorithm>
using namespace std;

#define bigint long long int
#define MAX 3010
#define MOD 1000000007
short array[MAX];
int len;

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

void fastio_arr(void)
{
    len = 0;
    char p; 

    do
    {
        int n = 0;
        p = getchar();

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

        array[len] = n;
        ++len;
    } while(p > '\r'); // 不能用 != '\n',那样不能读取'\0',会一直等待,输入格式不是UNIX可能也会出问题
}

int main(void)
{
    int t = fastio();
    while(t--)
    {
        int n = fastio();
        fastio_arr();

        sort(array, array + len);

        // 这里要用long long int，不然会溢出
        bigint r = 1;
        for(int i = 0; i < len; ++i)
            r = r * (array[i] - i) % MOD;

        printf("%lld\n", r);
    }

    puts("KILL BATMAN");

    return 0;
}
