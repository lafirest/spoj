// 这里看了github上的代码,发现了这个思路.不进行除法而是用乘法,避开浮点数和除0的问题.
// 原理是:如果向量a(x1,y1)、向量b(x2,y2)平行则有y1/x1 = y2/x2,两边同时乘以x1x2,则有
// y1x2 = y2x1,这样就把除法转换成了乘法判断
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 210
#define make_pair(x, y, z) (x << 17 | y << 1 | z)

struct dot
{
    int x;
    int y;
};

dot dots[MAX]; 
dot dirs[MAX * MAX];

bool cmp(dot& a, dot& b)
{
    return a.x * b.y < b.x * a.y;
}

bool equal(int i, int j)
{
    dot& a = dirs[i];
    dot& b = dirs[j];
    return a.x * b.y == b.x * a.y;
}

int main(void)
{
    int t;
    while(1)
    {
        scanf("%d", &t);
        if(!t)
            break;

        int x, y;
        for(int i = 0; i < t; ++i)
            scanf("%d %d", &dots[i].x, &dots[i].y);

        // 计算各个线段的方向
        int p = 0;
        for(int i = 0; i < t; ++i)
            for(int j = i + 1; j < t; ++j)
            {
                dirs[p].x = dots[i].x - dots[j].x;
                dirs[p].y = dots[i].y - dots[j].y;

                if(dirs[p].y < 0)
                {
                    // 统一保持y为正数
                    dirs[p].y = -dirs[p].y;
                    dirs[p].x = -dirs[p].x;
                } else if(!dirs[p].y && dirs[p].x < 0)
                    dirs[p].x = -dirs[p].x; // y = 0, 保证x为正数(-5,0)和(5,0)方向是一样的

                ++p;
            }

        sort(dirs, dirs + p, cmp);

        int r = 1;  // 至少有一条，计算不同的
        for(int i = 1; i < p; ++i)
            if(!equal(i - 1, i))
                ++r;

        printf("%d\n", r);
    }

    return 0;
}
