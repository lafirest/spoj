// 0.02s
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

// 快速io 只读
void fastio_v(void)
{
    char p = getchar();

    // 读取空白等
    while(p < '0')
        p = getchar( );

    // 读取数字
    while(p >= '0') 
        p = getchar( );
}

int main(void)
{
    int t = fastio();

    for(int i = 1; i <= t; ++i)
    {
        db.clear();
        int n = fastio();
        int r = fastio();

        while(r--)
        {
            int si = fastio();
            int c = fastio();
            int pair = make_pair(si, c);
            set<int>::iterator iter = db.find(pair);
            if(iter == db.end())
                db.insert(pair);
            else 
            {
                // 不符合条件,则读取完剩下的所有数,然后
                // 打印数据后直接jump结束此次循环.减
                // 少了分支判断
                while(r--)
                {
                    fastio_v();
                    fastio_v();
                }

                printf("Scenario #%d: impossible\n", i);
                goto end;
            }
        }

        
        printf("Scenario #%d: possible\n", i);

        end:;
    }

    return 0;
}
