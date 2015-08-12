// 晚上想起了以前遇到过右移出现的问题,早上来修改后ac了...
#include <cstdio>
#include <memory.h>
#include <queue>
#include <vector>
using namespace std;

#define make_pair(x,l) (l << 16 | x)
#define pair_l(pair) (pair >> 16)
#define pair_x(pair) (pair & 0x0000FFFF)

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
