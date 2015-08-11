// 简单的bfs问题,注意memset是按照字节来初始化的,所以inf是0x7F,ninf是0x80
// 还有一个就是边界问题,path和src的最小应为x[22][22],因为m和n最大时为20,
// bfs的判断会取下一个索引,则出现的最大下标是21,所以数组的大小是22
#include <queue>
#include <cstdio>
#include <memory.h>
using namespace std;
#define make_pair(x, y) ((x) << 8 | (y))
#define pair_x(x) (x >> 8)
#define pair_y(x) (x & 0xFF)
#define inf 0x7F
#define ninf 0x80

int path[30][30];
int src[30][30];
queue<short> series;

void
bfs(int sx, int sy, int m, int n)
{
    series.push(make_pair(sx,sy));
    path[sx][sy] = src[sx][sy];
    while(!series.empty())
    {
        int pair = series.front();
        series.pop();
        int x = pair_x(pair);
        int y = pair_y(pair);
        int value = path[x][y];
        int xnv = src[x+1][y];
        int ynv = src[x][y+1];
        
        int nxnv = value - xnv;
        if(nxnv >= 0 && nxnv > path[x+1][y])
        {
            path[x+1][y] = nxnv;
            series.push(make_pair(x+1, y));
        }

        int nynv = value - ynv;
        if(nynv >= 0 && nynv > path[x][y+1])
        {
            path[x][y+1] = nynv;
            series.push(make_pair(x, y+1));
        }
    }
}

int
main(void)
{
    int m,n,x,y; 
    scanf("%d %d", &m, &n);
    scanf("%d %d", &x, &y);
    memset(path, ninf, sizeof(path));
    memset(src, inf, sizeof(src));
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            scanf("%d", &src[i][j]);
    bfs(x, y, m, n);

    int result = path[m][n];
    if(result < 0)
        printf("N\n");
    else
        printf("Y %d\n", result);

    return 0;
}
