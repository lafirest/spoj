// 这道题目开始没明白什么意思,以为就是钱加起来除以单价,百思不得其解...
// 其实题目的意思是:成对的买.所以实际的需求就是,某两个数字加起来刚好为
// 单价,就算购买成功,然后这道题目的答案就是求有多个对这样的组合.
// 可以的实现方案：
//  1.用红黑树来存储,然后从头开始遍历,搜索是否存在(m - 当前的钱)这样的数,
//  评论里面说有tle,因为每次读取一个数就是一次插入操作,所以这里的插入和查询
//  的总操作是2n,时间复杂度是2n * log(n)
//  2.使用hash方法,一次数组存输入的数字,一个bool数组存对应位置是否有数字,遍历
//  数组,然后看看(m - 当前的钱)的位置是否为true.这里的问题主要是hash表的重置,
//  每次读取是n，遍历是n.C语言版本采用的这种算法,但问题是m的范围没有指定,数据
//  其实很离散,不太适合用hash
//  3.这里的解法是用二分查找,读入数据后,排序，然后从当前位置到数组尾部搜索
//  (m - 当前的钱).读取的效率是n,排序是n * log(n), 查找是log(n) + log(n - 1) + log(n - 2) ... log(1),
//  时间复杂度是n + n * log(n) + ...,比红黑树的方法要快些
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 100100

int array[MAX];

int fastio(void)
{
    int n = 0;
    int s = 1;

    char p = getchar();

    // 读取空白等
    while((p < '-' || p > '9') && p != EOF)
        p = getchar( );

    // 读取符号位
    if(p == '-')
    {
        s = -1;
        p = getchar( );
    }

    // 生成数字
    while(p >= '0' && p <= '9')
    {
        // n = n * 10 + (p - '0')
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar( );
    }

    return n * s;
}

bool search(int low, int high, int value)
{
    while(low <= high)
    {
        int mid = (low + high) >> 1;
        int midv = array[mid];
        if(midv == value)
            return true;
        else if(midv > value)
            high = mid - 1;
        else 
            low = mid + 1;
    }

    return false;
}

int main(void)
{
    int t = fastio();

    while(t--)
    {
        int n = fastio();
        int m = fastio();

        for(int i = 0; i < n; ++i)
            array[i] = fastio();

        int count = 0;

        sort(array, array + n);

        for(int i = 0; i < n; ++i)
            if(search(i + 1, n - 1, m - array[i]))
                ++count;

        printf("%d\n", count);

    }

    return 0;
}
