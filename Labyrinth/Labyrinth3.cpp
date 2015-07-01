// 这个方案是找到所有的分支然后做dfs，前提假设是一个分支最长的
// 两个路径和就是这个经过这个分支的路线里面的最佳解.
// 但这个前提假设是错的,两条线路如果都是从顶点过来的化就对,但有
// 一条如果是从另外一个分支过来的化,比如当前分支是B1,顶点是B,C
// 另外一个分支是B2，B1B = B1B2 + B2B， B1C = B1B2 + B2B，可见
// B1B和B2B并不能构成一条线,所以这个假设是错的
#include <utility>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <list>
using namespace std;

int maxpath;
int first;
int second;
char record[1024][1024];
int state[1024][1024];
int finded[10244][1024];
list<pair<int,int> > branch;

void scan(int pos, int r, int c)
{
    for(int j = 0; j < c; ++j)
    {
        if(record[pos][j] == '.')
        {
            int ud = record[pos-1][j];
            if(pos < r)
                ud += record[pos+1][j];

            if(ud > 70)
            {
                int lr = 0;
                if(j > 0)
                    lr = record[pos][j-1];
                if(j < c - 1)
                    lr += record[pos][j+1];

                if(lr > 70)
                {
                    branch.push_front(pair<int,int>(pos,j));
                    finded[pos][j] = 1;
                }
            }
        }
    }
}

void dfs(int r, int c, stack<pair<int,int> > stack)
{
    pair<int, int> point = stack.top();
printf("%d %d   ", point.first, point.second);
    while(!stack.empty())
    {
        pair<int, int> point = stack.top();
        stack.pop();

        int i = point.first;
        int j = point.second;
        int pushed = 0;

        if(record[i][j] == '#')
            continue;

        int rank = state[i][j] + 1;

        if(record[i-1][j] == '.' && record[i-1][j] != '#')
        {
            state[i-1][j] = rank;
            stack.push(pair<int, int>(i-1,j));
            ++pushed;
        }

        if(i < r && record[i+1][j] == '.' && record[i+1][j] != '#')
        {
            state[i+1][j] = rank;
            stack.push(pair<int, int>(i+1,j));
            ++pushed;
        }

        if(j > 0 && record[i][j-1] == '.' && record[i][j-1] != '#')
        {
            state[i][j-1] = rank;
            stack.push(pair<int, int>(i,j-1));
            ++pushed;
        }

        if(j < c && record[i][j+1] == '.' && record[i][j+1] != '#')
        {
            state[i][j+1] = rank;
            stack.push(pair<int, int>(i,j+1));
            ++pushed;
        }

        record[i][j] = '#';
        finded[i][j] = 0;
        if(pushed == 0)
        {
            --rank; 
            if(rank > first)
            {
                second = first;
                first = rank;
            }
            else if(rank > second)
                second = rank;
            printf("%d %d\n", first, second);
        }
    }
    
    int value = first + second;
    if(value > maxpath)
        maxpath = value;
}

int main(void)
{
    int t,c,r;
    cin >> t;
    while(t--)
    {
        maxpath = 0;
        first = 0;
        second = 0;
        cin >> c >> r;
        for(int i = 1; i <= r; ++i)
            cin >> record[i];

        for(int i = 1; i <= r; ++i)
            scan(i, r, c);

        list<pair<int,int> >::iterator Iter = branch.begin();
        for(;Iter !=branch.end(); ++Iter)
        {
			pair<int,int> point = *Iter;
            if(!finded[point.first][point.second])
                continue;
       
            state[point.first][point.second] = 0;
            stack<pair<int,int> > stack;
            stack.push(point);
            dfs(r, c, stack);
        }

        printf("Maximum rope length is %d.\n", maxpath);
    }
    return 0;
}
