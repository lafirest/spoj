// 这个是错误的解法.WA
// 这里将一个的值设置为1 一个为-1,然后来统计线段后,然后这个
// 只能判断是否线段是否拥有相等数量的左右括弧,但这些括弧的顺序
// 并不一定符合要求,必然)))(((...白痴呀
#include <stdio.h>

#define left(node) ((node) << 1)
#define right(node) (1 + ((node) << 1))

int sg[300000];
char buffer[40000];

void build(int p, int l, int r)
{
    int mid;
    if(l == r)
    {
        if(buffer[p] == '(')
            sg[p] = 1;
        else 
            sg[p] = -1;
    }
    else 
    {
        mid = (l + r) >> 1;
        build(left(p), l, mid);
        build(right(p), mid + 1, r);
        sg[p] = sg[left(p)] + sg[right(p)];
    }
}

void update(int p, int l, int r, int u)
{
    int mid;
    if(l == u && r == u)
        sg[p] = -sg[p];
    else
    {
        mid = (l + r) >> 1;
        if(u <= mid)
            update(left(p), l, mid, u);
        else
            update(right(p), mid + 1, r, u);

        sg[p] = sg[left(p)] + sg[right(p)];
    }
}

int main(void)
{
    int t = 10,n,on,op;
    for(t = 1; t <= 10; ++t)
    {
        scanf("%d", &n);
        scanf("%s", buffer + 1);
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
