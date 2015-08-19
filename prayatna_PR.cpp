// 图连通性问题,使用染色法
#include <stdio.h>
#include <list>
using namespace std;

#define MAX 100010
list<int> graph[MAX];
int visited[MAX];
int color = 0;

int
dfs(int i, int newcolor)
{
    // 节点访问过返回之前染的色
    if(visited[i])
        return visited[i];

    // 没有找到访问过的节点,返回新分配的颜色
    list<int> plist = graph[i];
    if(plist.empty())
        return newcolor;

    // 染色
    visited[i] = newcolor;
    int find = newcolor;

    // 遍历链表,对每个节点进行染色
    list<int>::iterator iter = plist.begin();
    while(iter != plist.end())
    {
        int p = *iter;
        int temp = dfs(p, newcolor);

        // 如果某个节点和染过色的节点相同,更新find的颜色
        if(temp < find)
            find = temp;
        
        // 这里其实有个问题,所有节点都被染成了新的颜色,不管其
        // 是否和之前染过色的节点相同.如果和之前某个节点相同,
        // 之后不更新color,则下次不合这些节点相同的颜色将被染成
        // 一样的
        // 这点和Herding不一样,Herding只有一个访问链,可以在递归返回
        // 时重新染色,而这里每个节点有很多分支,没法这么做
        
        ++iter;
    }

    // 重新染色(其实没必要)
    visited[i] = find;

    // 返回找到的颜色
    return find;
}

int
main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int peer, fnum;
        scanf("%d %d", &peer, &fnum);
        if(!fnum)
            printf("%d\n", peer);
        else
        {
            // 初始化颜色,访问标记和图
            color = 0;
            for(int i = 0; i < peer; ++i)
            {
                visited[i] = 0;
                graph[i].clear();
            }

            // 读取数据,建立图
            for(int i = 0; i < fnum; ++i)
            {
                int f1, f2;
                scanf("%d %d", &f1, &f2);
                graph[f1].push_front(f2);
                graph[f2].push_front(f1);
            }

            // 遍历所有节点,对没有染色的节点染色
            for(int i = 0; i < peer; ++i)
            {
                if(visited[i])
                    continue;

                int newc = color + 1;
                int temp =  dfs(i, newc);

                // 如果返回的是newc,则说明改节点(包括和它连通的节点)不合
                // 其他染过色的连通,分配新的颜色
                if(temp == newc)
                    ++color;
            }

            printf("%d\n", color);
        }
    }
}
