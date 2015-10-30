// 没搞懂数学原理,找规律+看其他人的代码.比如第二个5和8,
// 如果第一个放在[5,8]之间,则有3 * 5种方法,如果放在5以内则
// 有4 * 5种方法,共用5 * 7(8-1)种方法.
// 这是排列组合的问题...但是都忘记的差不多了
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
    } while(p > '\r'); // 不能用 != '\n', 看来输入格式不是UNIX

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
