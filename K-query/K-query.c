#include <stdio.h>

#define lowbit(x) ((x) & -(x))
#define MAX 500000 

int tree[MAX] = {0};
int res[MAX] = {0};
int n;

struct nodes
{
    int l;          //查询的左区间
    int r;          //右区间
    int v;          //值
    int type;       //类型,1代表是序列中的数,0代表是查询的数
    int pos;        //查询的数原本的位置
};

struct nodes nodes[MAX];

// 更新BIT
void update(int x)
{
    while(x <= n)
    {
        ++tree[x]; 
        x += lowbit(x);
    }
}

// 在BIT中求和
int sum(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += tree[x];
        x -= lowbit(x);
    }

    return sum;
}

// 排序比较函数
int cmp(void *a, void *b)
{
    struct nodes *x = (struct nodes*)a;
    struct nodes *y = (struct nodes*)b;
    if(x->v != y->v)
        return y->v - x->v;
    else
        return x->type - y->type;
}

int main(void)
{
    int i, t, j, v;
    // 读入整个序列以及需要查询的数
    scanf("%d", &n);
    for(i = 1; i <= n; ++i)
    {
        scanf("%d", &nodes[i].v);
        nodes[i].l = nodes[i].r = i;
        nodes[i].type = 1;
    }

    scanf("%d", &t);
    for(i = 1; i <= t; ++i)
    {
       scanf("%d %d %d", &nodes[i+n].l, &nodes[i+n].r, &nodes[i+n].v);
       nodes[i+n].pos = i;
       nodes[i+n].type = 0;
    }

    // 按照数进行降序排列,如果值相等,则需要查询的数在前面(保证不受更新的影响)
    qsort(nodes + 1, t+n, sizeof(struct nodes), cmp);

    // 遍历整个数组
    for(i = 1; i <= n + t; ++i)
    {
        // 如果当前的值是序列中的数,则BIT中对应位置更新加1
        // 这道问题里面5先更新入BIT，则此时BIT中sum(x) = 1,表示
        // 大于等于5的数有1个,之后如果查询4的话,则结果为1，因为
        // 大于等于5则必然大于4
        if(nodes[i].type) 
            update(nodes[i].l);
        else
            // 如果是要查询的数,此时sum(r)代表是在序列0~r位置上大于v的数的个数(
            // 因为序列中比v大的数都更新到BIT中了,而小于等于v的数还没有更新到BIT中去)
            // sum(l-1)是0~l-1位置上大于v的数的个数.左边减1的目的是因为sum(x)
            // 代表0 ~ x(包含x),所以如果不减1,则x这个位置上大于v的数将不会被统计到了
            res[nodes[i].pos] = sum(nodes[i].r) - sum(nodes[i].l - 1);
    }

    for(i = 1; i <= t; ++i)
        printf("%d\n", res[i]);
    
    return 0;
}
