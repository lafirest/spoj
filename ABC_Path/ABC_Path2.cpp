// 因为前面bfs超时了,所以这儿换用dfs，而且不从A开始搜索,因为A是确定的起点,但是终点无法
// 确定,从A开始的话,无法确定哪一次应该结束搜索.所以这里的做法是从最后的那个节点开始做
// dfs搜索,一旦哪次搜索能够到达A,则此次搜索结束.
#include<cstdio>
#include<set>
#include<memory.h>
using namespace std;

#define make_pair(al, x, y) (al << 16 | x << 8 | y)
#define pair_al(x) (x >> 16)
#define pair_x(x) ((x & 0xFFFF) >> 8) 
#define pair_y(x) (x & 0xFF)

char buffer[60][60];
char visited[60][60]; 
char op[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
// 这里从大到小排列,使最尾的字符排在最前面
set<int, greater<int> > series;
int tag = 0;

bool dfs(int i, int j)
{
    visited[i][j] = tag;

    char cur = buffer[i][j];
    if(cur == 'A')
        return true;

    char next = cur - 1;
    for(int z = 0; z < 8; ++z)
    {
        int zi = i + op[z][0];
        int zj = j + op[z][1];
        if(buffer[zi][zj] == next && visited[zi][zj] != tag)
        {
            if(dfs(zi, zj))
                return true;
        }
    }

    return false;
}

int main(void)
{
    int h, w, t = 0;
    while(true)
    {
        scanf("%d %d", &h, &w);
        if(h == 0 && w == 0)
            break;

        ++tag;
        ++t;
        memset(buffer, 0, sizeof(buffer));
        series.clear();

        for(int i = 1; i <= h; ++i)
        {
            scanf("%s", 1 + buffer[i]);
            for(int j = 1; j <= w; ++j)
                series.insert(make_pair(buffer[i][j], i, j));
        }

        set<int>::iterator Iter = series.begin();
        char max = 0;
        for( ; Iter != series.end(); ++Iter)
        {
            int pair = *Iter;  
            int i = pair_x(pair);
            int j = pair_y(pair);
            if(visited[i][j] == tag)
                continue;

            if(dfs(i, j))
            {
                max = pair_al(pair);
                break;
            }
        }
    
        int value = max ? max - 64 : 0;
        printf("Case %d: %d\n", t, value);
    }
    return 0;
}

