// 最长路径搜索的一种,这里使用的是bfs来查找,对时间的预期不足,bfs的好处是搜索的最后
// 一个节点必然是路径的最远点.因为无法知道从A出发最远能到哪个点,所以每一个A都要做一次
// 搜索.但实际上有可能某一次搜索就找到了最远的节点,后续搜索实际上就是在浪费时间,所以会
// 超时
#include<cstdio>
#include<queue>
#include<memory.h>
using namespace std;

#define make_pair(x, y) (x << 8 | y)
#define pair_x(x) (x >> 8)
#define pair_y(x) (x & 0xFF)

char buffer[60][60];
char visited[60][60]; 
char op[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
char cur;
int tag = 0;
queue<int> series;

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

        for(int i = 1; i <= h; ++i)
        {
            scanf("%s", 1 + buffer[i]);
            for(int j = 1; j <= w; ++j)
                if(buffer[i][j] == 'A')
                    series.push(make_pair(i, j));
        }

        while(!series.empty())
        {
            int pairs = series.front();            
            series.pop();
            int i = pair_x(pairs);
            int j = pair_y(pairs);

            visited[i][j] = tag;

            cur = buffer[i][j];
            char next = cur + 1;

            for(int z = 0; z < 8; ++z)
            {
                int zi = i + op[z][0];
                int zj = j + op[z][1];
                if(buffer[zi][zj] == next && visited[zi][zj] != tag)
                    series.push(make_pair(zi, zj));
            }
        }
    
        printf("Case %d: %d\n", t, cur - 'A' + 1);
    }

    return 0;
}

