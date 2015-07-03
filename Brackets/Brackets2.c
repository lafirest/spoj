// http://blog.csdn.net/u011561033/article/details/25288691
// 最近这几道题目都是方向是对的,但是具体实现是错的,需要看别人
// 的代码,找到关键点才行,需要多反思反思了.
// 方案一的问题就是把不能匹配的给匹配了,比如)(,所以线段树的每个
// 节点记录左边没匹配和右边没匹配的节点,更新父节点时,左边的左括号
// 必然可以和右边的右括号匹配,所以两者中小的就是合并线段时,父节点
// 可以消去的括号数,这样剩下的就是该节点处尚不能匹配的括号
//
// 问题:
//  1.线段树的问题做个两个了,上一个还很流畅,而做这个时连节点的更新
//  和构建都记不清除了
//  2.很简单的问题，却没有独立完成,急于求成了
#include <stdio.h>

#define left(node) ((node) << 1)
#define right(node) (1 + ((node) << 1))
#define pair(l, r) ( l << 16 | r)
#define pair_l(x) (x >> 16)
#define pair_r(x) (x & 0xFFFF)
#define min(a,b) (a) < (b) ? (a) : (b)

int sg[300000];
char buffer[40000];
int pos;

void build(int p, int l, int r)
{
    int mid, temp, plc, prc, pl, pr;
    if(l == r)
    {
        if(buffer[pos] == '(')
            sg[p] = pair(1, 0);
        else 
            sg[p] = pair(0, 1);
        ++pos;
    }
    else 
    {
        mid = (l + r) >> 1;
        build(left(p), l, mid);
        build(right(p), mid + 1, r);
        plc = sg[left(p)];
        prc = sg[right(p)];
        temp = min(pair_l(plc), pair_r(prc));
        pl = pair_l(plc) + pair_l(prc) - temp;
        pr = pair_r(plc) + pair_r(prc) - temp;
        sg[p] = pair(pl, pr);
    }
}

void update(int p, int l, int r, int u)
{
    int mid, pl, pr, plc, prc, temp;
    if(l == u && r == u)
    {
        pl = pair_l(sg[p]) ^ 1;
        pr = pair_r(sg[p]) ^ 1;
        sg[p] = pair(pl, pr);
    }
    else
    {
        mid = (l + r) >> 1;
        if(u <= mid)
            update(left(p), l, mid, u);
        else
            update(right(p), mid + 1, r, u);

        plc = sg[left(p)];
        prc = sg[right(p)];
        temp = min(pair_l(plc), pair_r(prc));
        pl = pair_l(plc) + pair_l(prc) - temp;
        pr = pair_r(plc) + pair_r(prc) - temp;
        sg[p] = pair(pl, pr);
    }
}

int main(void)
{
    int t = 10,n,on,op;
    int j;
    for(t = 1; t <= 10; ++t)
    {
        scanf("%d", &n);
        scanf("%s", buffer);
        pos = 0;
        build(1, 1, n);

        scanf("%d", &on);
        printf("Test %d:\n", t);
        while(on--)
        {
            scanf("%d", &op);
            if(op)
                update(1, 1, n, op);
            else 
            {
                if(sg[1])
                    puts("NO");
                else
                    puts("YES");
            }
        }
    }

    return 0;
}
