// 这里的想法是算出各个线段的方向,然后去掉方向相同的,直接按照题目的要求来解
// 问题是浮点数的精度和比较问题，以及除0问题.然后这里不进行除,而是约分将其
// 换成分数的形式.但是一直是wa...具体是哪儿错了,也不明白
// WA
#include <cstdio>
#include <set>
#include <cfloat>
#include <cmath>
using namespace std;

#define MAX 210
#define make_pair(x, y, z) (x << 17 | y << 1 | z)

struct dot
{
    int x;
    int y;
};

set<int> dirs;
dot dots[MAX]; 

int gcd(int a, int b)
{
    if(!b)
        return a;

    return gcd(b, a % b);
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

        dirs.clear();
        for(int i = 0; i < t; ++i)
            for(int j = i + 1; j < t; ++j)
            {
                int dirx = dots[i].x - dots[j].x;
                int diry = dots[i].y - dots[j].y;

                int flag = 0;
                int dirxv = 0;
                int diryv = 0;
                if(dirx != 0 && diry != 0)
                {
                    int g = gcd(dirx, diry);
                    dirxv = dirx / g;
                    diryv = diry / g;

                    if(dirxv * diryv < 0)
                        flag = 1;

                    if(dirxv < 0)
                        dirxv = -dirxv;

                    if(diryv < 0)
                        diryv = -diryv;
                }
                else if(dirx)
                {
                    dirxv = 1;
                    if(dirx < 0)
                        flag = 1;
                }
                else 
                {
                    diryv = 1;
                    if(diry < 0)
                        flag = 1;
                }

                int dirv = make_pair(dirxv, diryv, flag);
                dirs.insert(dirv);
            }

        printf("%d\n", dirs.size());
    }

    return 0;
}
