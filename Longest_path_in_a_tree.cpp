// 求边长为1的图里的最长路径,用dfs+dfs或则bfs+bfs都能实现,考虑到顶点数量比较大,如果
// 不使用stack的话,递归会导致栈溢出,所以这儿用bfs+bfs来做的
#include <cstdio>
#include <queue>
#include <list>
#include <memory.h>
using namespace std;

int vis[10001];
int dist[10001];
list<int> vertex[10001];

int color = 1;
int maxv = 0;
int maxver = 1;

int 
bfs(int start)
{
    queue<int> series;
    series.push(start);
    maxv = 0;
    maxver = 1;
    
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

        list<int>& vlist = vertex[pos];

        list<int>::iterator iter = vlist.begin();
        while(iter != vlist.end())
        {
            int npos = *iter;

            if(vis[npos] != color)
            {
                dist[npos] = dist[pos] + 1;
                series.push(npos);
            }

            ++iter;
        }
    }

    ++color;
}

int
main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i < n; ++i)
    {
        int u,v;
        scanf("%d %d", &u, &v);
        vertex[u].push_front(v);
        vertex[v].push_front(u);
    }
    
    bfs(1);
    memset(dist + 1, 0, sizeof(int) * n);

    bfs(maxver);

    printf("%d\n", maxv);
    return 0;
}
