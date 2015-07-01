// 这个是方案2的改良
// http://algorithmist.com/index.php/SPOJ_LABYR1 看这里.从一个顶点出发做一次dfs,找到离这个点最远的一个
// 顶点，这个点就是方案4里面的那个"恰好是"的顶点了,对这个顶点再做一次dfs就能求出解,O(2n^2)
// 这个迷宫可以看成一颗树(图),从一个节点开始搜索到的最远节点,必然是树两个最远端点中的一个,从这个端点做
// dfs所搜索到的最大值,即是树中两个最远端点间的距离,也就是这个迷宫中的最长路径了
#include <utility>
#include <set>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

// 不使用stl的pair，用位运算,加快速度
#define make_pair(x, y) (x << 16 | y)
#define pair_i(x) (x >> 16)
#define pair_j(x) (x & 0xFFFF)
int maxpath;
int tag = 0;                // 标记,防止重复搜索
char record[1024][1024];    // 记录输入
int state[1024][1024];      // 记录值
int finded[10244][1024];    // 记录标记

void dfs(int i, int j, int r, int c, int times)
{
    int maxi = 0;
    int maxj = 0;
    state[i][j] = 0;        // 开始前需要重置这个位置的值(清掉上一次赋的值)

    // dfs迭代搜索用的栈
    stack<int> stack;
    stack.push(make_pair(i,j));

    // 用tag来区分不同次的搜索
    ++tag;

    while(!stack.empty())
    {
        int point = stack.top();
        stack.pop();

        int i = pair_i(point);
        int j = pair_j(point);

        // 搜索过的就不搜索了
        if(finded[i][j] == tag)
            continue;

        // 标记
        finded[i][j] = tag;

        int rank = state[i][j] + 1;

        // 将上下左右四个方向需要更新的点push到stack中
        if(record[i-1][j] == '.')
        {
            state[i-1][j] = rank;
            stack.push(make_pair(i-1,j));
        }

        if(i < r && record[i+1][j] == '.')
        {
            state[i+1][j] = rank;
            stack.push(make_pair(i+1,j));
        }

        if(j > 0 && record[i][j-1] == '.')
        {
            state[i][j-1] = rank;
            stack.push(make_pair(i,j-1));
        }

        if(j < c - 1 && record[i][j+1] == '.')
        {
            state[i][j+1] = rank;
            stack.push(make_pair(i,j+1));
        }

        // 更新最大路径和对应的点
        if(rank > maxpath)
        {
            // rank代表的是后续节点的值,但顶点是
            // 没有后续节点的,所以搜索到顶点处时
            // 保存的maxpath应该-1,但这儿可以不用判断
            // 在输出时-1即可
            maxpath = rank;
            maxi = i;
            maxj = j;
        }
    }

    if(times < 1)
        return dfs(maxi, maxj, r, c, 1);
}

int main(void)
{
    // 因为输入数据太多,这里需要关闭缓存同步,加快速度
    std::ios::sync_with_stdio(false);
    int t,c,r;
    cin >> t;
    while(t--)
    {
        maxpath = 1;
        cin >> c >> r;
        for(int i = 1; i <= r; ++i)
            cin >> record[i];

        bool scan = true;

        // 从第一个点开始搜索到的第一个freeblock必然是顶点
        // 所以没必要做顶点判断,在顶点处做一次dfs即可,既要
        // 跳出本层循环,也要跳出外层循环(开始就是没有跳出外层
        // 循环导致了多次超时)
        for(int i = 1; i <= r && scan; ++i)
            for(int j = 0; j < c; ++j)
                if(record[i][j] == '.')
                {
                    scan = false;
                    dfs(i, j, r, c, 0);
                    break;
                }

        printf("Maximum rope length is %d.\n", maxpath - 1);
    }
    return 0;
}
