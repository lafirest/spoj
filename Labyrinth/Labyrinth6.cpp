// 很奇怪为什么没有方案5
// 这个方案的做法是求出每个分支到能够到达的最远的顶点的距离,如果在dfs中
// 遇到的是另外一个分支点,则不把距离纳入计算,也就是说是方案3的改良,每个
// 分支只计算能够到达的顶点的距离,而如果中途由另外一个分支,则把这个分支放入
// 队列.当前这个分支做完处理后,取出另外一个分支,这个分支进行重复的处理,
// 这个分支的最大值为:max(该分支的能够到达的最长距离, 上一个分支提供给它的距离)
// 对于没有分支的则用路径点数-1得到路径长度
// 理论这在方法是能求出解的,test也都正确的,但spoj上会得到wa.具体原因不清除
#include <utility>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <queue>
#include <list>
using namespace std;

int maxpath;
int freecount;
char record[1024][1024];
pair<int, int> state[1024][1024];

void dfs(int i, int j, int r, int c)
{
    pair<int, int> start(i, j);
    queue<pair<int, int> > branch;
    branch.push(start);

    stack<pair<int, int> > next;
    int last_max = 0;

    while(!branch.empty())
    { 
        pair<int, int> bpoint = branch.front();
        pair<int, int>& bstate = state[bpoint.first][bpoint.second];
        bstate.first += last_max;
        pair<int, int> temp = state[bpoint.first][bpoint.second];
        bstate.first = 0;
        bstate.second = 0;
        branch.pop();

        next.push(bpoint);

        while(!next.empty())
        {
            pair<int, int> point = next.top();
            next.pop();

            int i = point.first;
            int j = point.second;
            int ud = 0;
            int lr = 0; 

            int rank = state[i][j].first + 1;

            if(record[i-1][j] == '.' && record[i-1][j] != '#')
            {
                state[i-1][j].first = rank;
                next.push(pair<int, int>(i-1,j));
                ++ud;
            }

            if(i < r && record[i+1][j] == '.' && record[i+1][j] != '#')
            {
                state[i+1][j].first = rank;
                next.push(pair<int, int>(i+1,j));
                ++ud;
            }

            if(j > 0 && record[i][j-1] == '.' && record[i][j-1] != '#')
            {
                state[i][j-1].first = rank;
                next.push(pair<int, int>(i,j-1));
                ++lr;
            }

            if(j < c - 1 && record[i][j+1] == '.' && record[i][j+1] != '#')
            {
                state[i][j+1].first = rank;
                next.push(pair<int, int>(i,j+1));
                ++lr;
            }

            if(ud && lr && point != bpoint)
            {
                --rank;
                int len = ud + lr;
                while(len--)
                    next.pop();

                state[i][j].first = rank;
                branch.push(point);
            }
            else if(!(ud | lr))
            {
               --rank;
               if(rank > bstate.first)
               {
                    bstate.second = bstate.first;
                    bstate.first = rank;
               }
               else if(rank > bstate.second)
                    bstate.second = rank;
            }
        
            record[i][j] = '#';
        }

        if(temp.first > bstate.first)
        {
            bstate.second = bstate.first;
            bstate.first = temp.first;
        }
        else if(temp.first > bstate.second)
            bstate.second = temp.first;

        int bMax = bstate.first + bstate.second;
        if(bMax > maxpath)
            maxpath = bMax;

        last_max = bstate.first;
    }
}

void scan(int pos, int r, int c)
{
    for(int j = 0; j < c; ++j)
    {
        state[pos][j].first = 0;
        state[pos][j].second = 0;
        if(record[pos][j] == '.')
        {
            int udbranch = 70;
            int lrbranch = 70;
            int ud = 0;
            ++freecount;
            if(pos == 1)
                udbranch -= 35;
            else
                ud += record[pos-1][j];

            if(pos < r)
                ud += record[pos+1][j];
            else 
                udbranch -= 35;

            if(ud > udbranch)
            {
                int lr = 0;
                if(j > 0)
                    lr = record[pos][j-1];
                else 
                    lrbranch -= 35;

                if(j < c - 1)
                    lr += record[pos][j+1];
                else 
                    lrbranch -= 35;

                if(lr > lrbranch)
                {
                    dfs(pos, j, r, c);
                    freecount = 0;
                    break;
                }
            }
        }
    }
}

int main(void)
{
    int t,c,r;
    cin >> t;
    while(t--)
    {
        maxpath = 0;
        freecount = 0;
        cin >> c >> r;
        for(int i = 1; i <= r; ++i)
            cin >> record[i];

        for(int i = 1; i <= r; ++i)
            scan(i, r, c);

        if(freecount)
            maxpath = freecount - 1;

        printf("Maximum rope length is %d.\n", maxpath);
    }
    return 0;
}
