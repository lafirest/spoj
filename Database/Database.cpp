// 这里的算法很简单,写这么多版本只是想提高运行速度.
// 0.03s
#include <cstdio>
#include <set>
using namespace std;

#define make_pair(x,y) ((x) << 16 | (y))

set<int> db;

// 快速io
int fastio(void)
{
    int n = 0;
    int s = 1;

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

    return n * s;
}

int main(void)
{
    int t = fastio();

    for(int i = 1; i <= t; ++i)
    {
        db.clear();
        bool possible = true;
        int n = fastio();
        int r = fastio();

        while(r--)
        {
            int i = fastio();
            int c = fastio();

            // 这里也有分支预测的开销,而且为false之后,实际上就没必要继续判断了
            if(possible)
            {
                int pair = make_pair(i, c);
                set<int>::iterator iter = db.find(pair);

                if(iter == db.end())
                    db.insert(pair);
                else 
                    possible = false;
            }
        }

        // 这里每次都会有分支预测的开销
        if(possible)
            printf("Scenario #%d: possible\n", i);
        else
            printf("Scenario #%d: impossible\n", i);
    }

    return 0;
}
