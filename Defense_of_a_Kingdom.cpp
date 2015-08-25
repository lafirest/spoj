// 贪心问题,细节需要注意.最大的无人防守区域,就是横向最大防守间距 * 纵向最大防守间距
// 需要注意的有三点:
//  1.n为0时,无防守
//  2.下界为0,数组中这个地方需要留着
//  3.上界是w+1和h+1(棋盘外的当作有防守)而不是w,h
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 40010
int warray[MAX];
int harray[MAX];

int 
main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int w, h, n;
        int mx = 0;
        int my = 0;

        scanf("%d %d %d", &w, &h, &n);
        if(n == 0)
            printf("%d\n", w * h);
        else
        {
            for(int i = 1; i <= n; ++i)
                scanf("%d %d", &warray[i], &harray[i]);

            warray[n+1] = w + 1;
            harray[n+1] = h + 1;

            // 最后一位是最大值,所以不需要参与排序
            sort(warray + 1, warray + n + 1);
            sort(harray + 1, harray + n + 1);

            // 求出两个方向的最大间距
            for(int i = 1; i <= n + 1; ++i)
            {
                int ndx = warray[i] - warray[i-1] - 1;
                if(ndx > mx)
                    mx = ndx;

                int ndy = harray[i] - harray[i-1] - 1;
                if(ndy > my)
                    my = ndy;
            }

            printf("%d\n", mx * my);
        }
    }

    return 0;
}
