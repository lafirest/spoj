// 这道题目开始想到的是dp，评论里面也确实有人用dp ac了的,
// 但构思了下觉得dp比较复杂,考虑了最简方案,可以实现,但没有
// 具体写出dp公式.看评论说贪心可以ac,想了下贪心更简单,然后就
// 用贪心来做了.思路就是越往后走切割一次乘以的份数就越大,得到
// 的值也越大,因此尽量把大的值放在前面,乘以小的份数,把小的值放
// 在后面乘以大的份数.另外一点就是先从m和n中小的那个开始切割,
// 这样得到的份数比从大的开始切割时要小.
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
priority_queue<int> pq[2];  //m和n的优先队列(用自排序结构都可以,或则用数组,之后排序也行)
int pieces[2];  //m和n两个方向上的份数.

int main(void)
{
    int t,m,n,pos,temp,s;
    cin >> t;
    while(t--)
    {
        int acc = 0;
        pieces[0] = 1;
        pieces[1] = 1;
        cin >> m >> n;
        // 判断m和n哪个更长,从短的那个方向开始切割
        if(m <= n)
            pos = 0;
        else
            pos = 1;

        scanf("\n");

        // 记录短的那个方向是哪个队列
        s = pos;
        
        // 读取数据
        --m;
        --n;
        while(m--)
        {
            cin >> temp;
            pq[0].push(temp);
        }
        while(n--)
        {
            cin >> temp;
            pq[1].push(temp);
        }

        // 先从最大的权值处开始,如果最大值不在短
        // 的那个方向,则交换下起始位置
        if(pq[pos].top() < pq[!pos].top())
            pos = !pos;

        // 循环直到切割完
        while(!pq[pos].empty())
        {
            int head = pq[pos].top();
            pq[pos].pop();

            // 每一次切割的消耗为权值 * 另外一个方向的份数
            acc += head * pieces[!pos];
            // 每一次切割会导致本方向的份数加1
            ++pieces[pos];

            // 判断下一个最大值在哪个队列
            if(pq[pos].top() < pq[!pos].top())
                pos = !pos;
            // 如果两个队列的第一个值一样大,从短的那个方向开始
            else if(pq[pos].top() == pq[!pos].top())
                pos = s;
                
            // 一个队列空了,就换到另外一个队列
            if(pq[pos].empty())
                pos = !pos;
        }

        cout << acc << endl;        
    }
    return 0;
}
