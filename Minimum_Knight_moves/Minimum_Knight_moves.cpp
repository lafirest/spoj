// 因为dfs会超时,所以这儿改用bfs了
#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;

#define INF 0x7FFFFFFF
#define make_pair(x, y) (x << 16 | y)
#define pair_x(x) (x >> 16)
#define pair_y(x) (x & 0xFFFF)

int state[9][9];
int visited[9][9];
int color = 1;
int value = INF;

// 马的移动位置
int point[][2] = 
{
    {-2, -1},
    {-2, 1},
    {-1, -2},
    {-1, 2},
    {2, -1},
    {2, 1},
    {1, -2},
    {1, 2}
};

void
bfs(int i, int j, int ex, int ey)
{
    queue<int> series;
    series.push(make_pair(i, j));

    while(!series.empty())
    {
        int pair = series.front();
        series.pop();

        int px = pair_x(pair);
        int py = pair_y(pair);

        visited[px][py] = color;
        int rank = state[px][py];
        if(px == ex && py == ey)
        {
            if(rank < value)
                value = rank;
        }
        else
        {
            ++rank;
            for(int z = 0; z < 8; ++z)
            {
                int* array = point[z];
                int ni = px + array[0];
                int nj = py + array[1];
                if(ni < 1 ||  ni > 8)
                    continue;

                if(nj < 1 || nj > 8)
                    continue;

                if(visited[ni][nj] == color)
                    continue;

                state[ni][nj] = rank;
                series.push(make_pair(ni, nj));
            }
        }
    }
}

int
main(void)
{
    int t;
    scanf("%d", &t);
    char buffer[8];
    while(t--)
    {
        scanf("%s", buffer); 
        memset(state, 0, sizeof(state));
        int sy = buffer[0] - 'a' + 1;
        int sx = buffer[1] - '0';

        scanf("%s", buffer); 
        int ey = buffer[0] - 'a' + 1;
        int ex = buffer[1] - '0';

        value = INF;
        bfs(sx, sy, ex, ey);
        ++color;
        printf("%d\n", value);
    }

    return 0;
}
