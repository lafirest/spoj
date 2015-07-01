// ps：方案一在改名时被这个覆盖了...
// 方案一的做法是找到所有顶点用递归进行dfs,会得到段错误,时间复杂度是
// O(kn^2)k为顶点数
// 和方案一的算法没有本质区别,只是把递归的dfs用stack来以迭代的方法实现
// 解决了段错误,但是超时,因为时间复杂度没有改变
#include <utility>
#include <set>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;

set<pair<int,int> > vertex;
int maxpath;
char record[1024][1024];
int state[1024][1024];
int finded[10244][1024];

void scan(int pos, int r, int c)
{
    for(int j = 0; j < c; ++j)
    {
        if(record[pos][j] == '.')
        {
            int sum = 0;
            int vertexl = 3;
            if(record[pos-1][j] == '#')
                ++sum;

            if(pos < r)
            {
                if(record[pos+1][j] == '#')
                    ++sum;
            }
            else 
                --vertexl;

            if(j > 0)
            {
                if(record[pos][j-1] == '#')
                    ++sum;
            }
            else    
                --vertexl;

            if(j < c)
            {
                if(record[pos][j+1] == '#')
                    ++sum;
            }
            else 
                --vertexl;

            if(sum == vertexl)
                vertex.insert(pair<int,int>(pos,j));
        }
    }
}

void dfs(int r, int c, int tag, stack<pair<int,int> > stack)
{
    while(!stack.empty())
    {
        pair<int, int> point = stack.top();
        stack.pop();

        int i = point.first;
        int j = point.second;

        if(finded[i][j] == tag)
            continue;

        int rank = state[i][j] + 1;

		if(rank > maxpath)
			maxpath = rank;

        if(record[i-1][j] == '.' && finded[i-1][j] != tag)
        {
            state[i-1][j] = rank;
            stack.push(pair<int, int>(i-1,j));
        }

        if(i < r && record[i+1][j] == '.' && finded[i+1][j] != tag)
        {
            state[i+1][j] = rank;
            stack.push(pair<int, int>(i+1,j));
        }

        if(j > 0 && record[i][j-1] == '.' && finded[i][j-1] != tag)
        {
            state[i][j-1] = rank;
            stack.push(pair<int, int>(i,j-1));
        }

        if(j < c && record[i][j+1] == '.' && finded[i][j+1] != tag)
        {
            state[i][j+1] = rank;
            stack.push(pair<int, int>(i,j+1));
        }

        finded[i][j] = tag;
    }
}

int main(void)
{
    int t,c,r;
    cin >> t;
    while(t--)
    {
        maxpath = 1;
        vertex.clear();
        cin >> c >> r;
        for(int i = 1; i <= r; ++i)
            cin >> record[i];

        for(int i = 1; i <= r; ++i)
            scan(i, r, c);

        set<pair<int,int> >::iterator Iter = vertex.begin();
        int tag = 1;
        while(Iter != vertex.end())
        {
			pair<int,int> point = *Iter;
			state[point.first][point.second] = 0;
            stack<pair<int,int> > stack;
            stack.push(point);
            dfs(r, c, tag, stack);
            ++Iter;
            ++tag;
        }

        printf("Maximum rope length is %d.\n", maxpath - 1);
    }
    return 0;
}
