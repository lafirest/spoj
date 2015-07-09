// 和那道舞厅里面能容纳多岁人的题目类似,不过那个是单纯的计算某个区间内的人数
// 这个则是贪心算法来着.想要找到尽可能多的任务,则从结束时间最早的开始早,结束
// 的越早则越可能有后续任务在这个结束时间后开始
#include <stdio.h>
#include <algorithm>
using namespace std;

struct node
{
    int start;
    int end;
};

node nodes[100000];

// 按照结束时间由小到大排序
bool complare(node s, node e)
{ 
    if(s.end == e.end)
        return s.start < e.start;
    else 
        return s.end < e.end;
}

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, s, e, value = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) 
        {
            
            node& p = nodes[i];
            scanf("%d %d", &p.start, &p.end);
        }

        sort(nodes, nodes + n, complare);

		++value;    // 至少有一个任务

        // 从结束时间最早的开始查找
        for(int i = 0, j = 1; i < n, j < n; )
        {
            // 后续任务在这个任务结束后开始,计数加1,然后从后续任务开始查找
            if(nodes[i].end <= nodes[j].start)
            {
                ++value;
                i = j;
                ++j;
            }
            else 
                ++j;    //找不到则向后继续找
        }

        printf("%d\n", value);
    }
}
