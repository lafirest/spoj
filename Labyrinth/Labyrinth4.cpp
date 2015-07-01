// 这个是从顶点开始做bfs,然而只能求出某个顶点到其他顶点的最长路径
// 并不一定是整个迷宫的最长路径,如果恰好求的是最长路径对应的那个顶点
// 的解,那么答案就正确了
#include <utility>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;

int color_alloc;
queue<pair<int,int> > vertex;
int maxpath;
char record[1024][1024];
int state[1024][1024];
int colors[1024][1024];

void scan(int i, int r, int c)
{
    for(int j = 0; j < c; ++j)
    {
        state[i][j] = 0;
        if(record[i][j] == '.')
        {
            int sum = 0;
            int vertexl = 3;
            if(record[i-1][j] != '.')
                ++sum;

            if(i < r)
            {
                if(record[i+1][j] == '#')
                    ++sum;
            }
            else 
                --vertexl;

            if(j > 0)
            {
                if(record[i][j-1] == '#')
                    ++sum;
            }
            else    
                --vertexl;

            if(j < c - 1)
            {
                if(record[i][j+1] == '#')
                    ++sum;
            }
            else 
                --vertexl;

            if(sum == vertexl)
            {
                vertex.push(pair<int,int>(i,j));
                colors[i][j] = color_alloc;
                ++color_alloc;
                printf("i:%d, j:%d, sum:%d vertexl:%d\n", i, j, sum, vertexl);
            }
        }
    }
}

void dfs(int r, int c) 
{
    while(!vertex.empty())
    {
        pair<int, int> point = vertex.front();
        vertex.pop();

        int i = point.first;
        int j = point.second;

        int rank = state[i][j] + 1;
        int color = colors[i][j];

        if(record[i-1][j] == '.' && state[i-1][j] <= rank && colors[i-1][j] != color)
        {
            state[i-1][j] = rank;
            colors[i-1][j] = color;
            vertex.push(pair<int, int>(i-1,j));
        }

        if(i < r && record[i+1][j] == '.' && state[i+1][j] <= rank && colors[i+1][j] != color)
        {
            state[i+1][j] = rank;
            colors[i+1][j] = color;
            vertex.push(pair<int, int>(i+1,j));
        }

        if(j > 0 && record[i][j-1] == '.' && state[i][j-1] <= rank && colors[i][j-1] != color)
        {
            state[i][j-1] = rank;
            colors[i][j-1] = color;
            vertex.push(pair<int, int>(i,j-1));
        }

        if(j < c - 1 && record[i][j+1] == '.' && state[i][j+1] <= rank && colors[i][j+1] != color)
        {
            state[i][j+1] = rank;
            colors[i][j+1] = color;
            vertex.push(pair<int, int>(i,j+1));
        }

        if(rank > maxpath)
            maxpath = rank;
    }
}

int main(void)
{
    int t,c,r;
    cin >> t;
    while(t--)
    {
        maxpath = 1;
        cin >> c >> r;
        for(int i = 1; i <= r; ++i)
            cin >> record[i];

        for(int i = 1; i <= r; ++i)
            scan(i, r, c);

        dfs(r, c);

        for(int i = 1; i <= r; ++i)
        {
            for(int j = 0; j < c; ++j)
                printf("%d ", state[i][j]);
            printf("\n");
        }

        printf("Maximum rope length is %d.\n", maxpath - 1);
    }
    return 0;
}
