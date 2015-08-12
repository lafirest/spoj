// 将版本2按照github上的代码改写后,ac了,但还是没清除为什么版本2错了
#include <cstdio>
#include <memory.h>
#include <queue>
#include <vector>
using namespace std;

int color = 1;
int maxv = 0;
int maxver = 1;

struct node
{
    int pos;
    int len;
};

vector<node> vertex[50011];
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
            node& info = vertex[pos][i];
            int npos = info.pos;
            int l = info.len;
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
    node temp;
    while(t--)
    {
        scanf("%d", &n); 
        for(int i = 1; i <= n; ++i)
            vertex[i].clear();

        int v1, v2, len;
        for(int i = 1; i < n; ++i)
        {
            scanf("%d %d %d", &v1, &v2, &len);
            temp.pos = v2;
            temp.len = len;
            vertex[v1].push_back(temp);
            temp.pos = v1;
            vertex[v2].push_back(temp);
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
