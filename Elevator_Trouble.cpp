// 这道题目意思简单,但不太能想到是用bfs来做,因为这是个一维数组,很难想到用bfs.
// 变量有f(上界)、s(起点)、g(终点)、u(向上每次的步数)、d(向下每次的步数)
// 解法就是从起点开始分别向u、d两个方向做bfs,如果下一步没有越界且没有搜索过,则
// 加入队列,如果搜索到了终点则退出搜索,如果搜索完所有点依然不能到达终点，则无法
// 到达.
#include <cstdio>
#include <queue>
using namespace std;

#define MAX 1000100

char vis[MAX];
int color = 0;

struct info
{
    int pos;    //当前位置
    int step;   //经过了多少步(次)

    info(int p, int s)
    {
        pos = p;
        step = s;
    }
};

int main(void)
{
    int f,s,g;
    int dir[2];
    while(EOF != scanf("%d %d %d %d %d", &f, &s, &g, &dir[0], &dir[1]))
    {
        int value = 0;
        ++color;

        // 如果s=g,则不用搜索,直接打印
        if(s != g)
        {
            dir[1] *= -1;

            // 搜索起点
            queue<info> sersies;
            sersies.push(info(s, 0));

            while(!sersies.empty() && !value)
            {
                info cur = sersies.front();
                sersies.pop();

                for(int i = 0; i < 2; ++i)
                {
                    int pos = cur.pos + dir[i];
                    // 越界
                    if(pos < 1 || pos > f)
                        continue;

                    // 已经搜索过了
                    if(vis[pos] == color)
                        continue;

                    vis[pos] = color;
                    int step = cur.step + 1;

                    if(pos != g)
                        sersies.push(info(pos, step));
                    else
                    {
                        // 到达目标点
                        value = step;
                        break;
                    }
                }
            }

            if(value) 
                printf("%d\n", value);
            else
                printf("use the stairs\n");
        }
        else
            printf("0\n");

    }

    return 0;
}
