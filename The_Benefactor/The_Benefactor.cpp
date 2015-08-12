// 这个是lisp版本的改写,同样也有dfs栈溢出的问题
#include <cstdio>
#include <memory.h>
#include <list>
using namespace std;

#define make_pair(x,l) (x << 16 | l)
#define pair_x(pair) (pair >> 16)
#define pair_l(pair) (pair & 0x0000FFFF)

int maxv = 0;
int color = 1;
int maxver = 1;

list<int> vertex[50001];
short vis[50001];

void
dfs(int pos, int len)
{
    if(vis[pos] == color)
        return;

    vis[pos] = color;
    if(len > maxv)
    {
        maxv = len;
        maxver = pos;
    }

    list<int> vlist = vertex[pos];
    if(vlist.empty())
        return;

    list<int>::iterator iter = vlist.begin();
    while(iter != vlist.end())
    {
        int pair = *iter;    
        int x = pair_x(pair);
        int l = pair_l(pair);
        dfs(x, len + l);
        ++iter;
    }
}

int 
main(void)
{
    int t,n;
    scanf("%d", &t);
    while(t--)
    {
       maxv = 0;
       maxver = 1;

       scanf("%d", &n); 
       for(int i = 1; i <= n; ++i)
          vertex[i].clear();

       int v1, v2, len;
       for(int i = 1; i < n; ++i)
       {
            scanf("%d%d%d", &v1, &v2, &len);
            vertex[v1].push_front(make_pair(v2, len));
            vertex[v2].push_front(make_pair(v1, len));
       }

       dfs(1, 0);
       ++color;
printf("%d\n", maxver);
       dfs(maxver, 0);
printf("%d\n", maxver);
       ++color;

       printf("%d\n", maxv);
    }

    return 0;
}
