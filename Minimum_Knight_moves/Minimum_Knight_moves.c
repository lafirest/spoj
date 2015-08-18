// 这是一道搜索问题,因为dfs比bfs好写,所以最开始用dfs来做,dfs来做的化
// 需要进行回溯,即一个点虽然被访问过了,但如果它之前的深度比当前的大,
// 则重新更新这个点,这个回溯操作导致tle...然后改用bfs来做了
#include <stdio.h>
#include <memory.h>

#define INF 0x7FFFFFFF
int state[9][9];
int visited[9][9];
int color = 1;
int value = INF;

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
dfs(int i, int j, int ex, int ey, int depth)
{
    if(i == ex && j == ey)
    {
        if(depth < value)
            value = depth;

        return;
    }

    visited[i][j] = color;
    state[i][j] = depth;
    for(int z = 0; z < 8; ++z)
    {
        int* array = point[z];
        int ni = i + array[0];
        int nj = j + array[1];
        if(ni < 1 ||  ni > 8)
            continue;

        if(nj < 1 || nj > 8)
            continue;

        if(visited[ni][nj] == color && state[ni][nj] <= depth)
            continue;

        dfs(ni, nj, ex, ey, depth + 1);
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
        dfs(sx, sy, ex, ey, 0);
        ++color;
        printf("%d\n", value);
    }

    return 0;
}
