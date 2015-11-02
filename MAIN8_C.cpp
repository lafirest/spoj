// 和很久前做的奶牛问题一样,二分搜索+贪心算法
// 在一个范围内不断逼近解,最后一个符合条件的数就是答案了
#include <cstdio>
#include <functional>  
#include <algorithm>
using namespace std;

int candys[50000];
int n;
int k;

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
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar( );
    }

    return n;
}

// 按照这个数尝试进行分配
bool check(int value)
{
    int num = 0;
    for(int i = 0; i < n; ++i)
    {
        if(candys[i] < value)
            continue;

        num += candys[i] / value;

        if(num >= k)
            return true;
    }

    return false;
}

int main(void)
{
    int t = fastio();
    while(t--)
    {
        n = fastio();
        k = fastio();
        int high = 0;
        int low = 0; 
        int mid = 0;
        int r = 0;
        for(int i = 0; i < n; ++i)
        {
            int temp = fastio();
            if(temp > high)
                high = temp;

            candys[i] = temp;
        }

        //        sort(candys, candys + n, greater<int>());
        // 这里开始查找先排序,然后在check时方便跳出,结果无情的tle了

        //      while(low <= high)
        while(low < high)
        {
            //  基准点的选择,下面注释掉的代码会tle,注释下面的代码只需要
            //  0.01s.具体其实不是很明白
            //  mid = (low + high) >> 1;
            // if(mid == 0)
            //    mid = 1;

            mid = low + (high - low + 1) / 2;

            if(check(mid)) 
            {
                r = mid;
                low = mid;
            }
            else 
                high = mid - 1;
        }

        // 其实这里用low就可以了
        printf("%d\n", r);
    }

    return 0;
}
