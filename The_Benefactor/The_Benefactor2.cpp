// 这个版本使用了bfs,出现错误的原因是位运算,一个有符号数右移还是会得到一个
// 有符号数,所以把最大为50000的顶点放在高位,会导致最后还原出一个负数
#include <cstdio>
#include <memory.h>
#include <queue>
#include <vector>
using namespace std;

#define make_pair(x,l) (x << 16 | l)
#define pair_x(pair) (pair >> 16)
#define pair_l(pair) (pair & 0x0000FFFF)

int color = 1;
int maxv = 0;
int maxver = 1;

vector<int> vertex[50011];
int vis[50011];
int dist[50011];
queue<int> series;

void
bfs(int start)
{
    maxv = 0;
    maxver = 1;
    series.push(start);

    while(!series.empty())
    {
        int pos = series.front();
        series.pop();

        vis[pos] = color;

        if(dist[pos] > maxv)
        {
            maxv = dist[pos];
            maxver = pos;
        }

        for(int i = 0; i < vertex[pos].size(); ++i)
        {
            int pair = vertex[pos][i];
            int npos = pair_x(pair);
            int l = pair_l(pair);
            if(vis[npos] != color)
            {
                dist[npos] = dist[pos] + l;
                series.push(npos);
            }
        }
    }
}

int 
main(void)
{
    int t,n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n); 
        for(int i = 1; i <= n; ++i)
            vertex[i].clear();

        int v1, v2, len;
        for(int i = 1; i < n; ++i)
        {
            scanf("%d %d %d", &v1, &v2, &len);
            vertex[v1].push_back(make_pair(v2, len));
            vertex[v2].push_back(make_pair(v1, len));
        }

        memset(dist + 1, 0, sizeof(int) * n);
        bfs(1);
        ++color;

        memset(dist + 1, 0, sizeof(int) * n);
        bfs(maxver);
        ++color;

        printf("%d\n", dist[maxver]);
    }

    return 0;
}
