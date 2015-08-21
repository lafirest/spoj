// lca问题,这里用简单的dfs染色,效率比想象的要好许多
// 对第一个节点进行dfs直到根节点,对沿途的节点染色,
// 然后对第二个节点做dfs,遇到的第一个染了色的节点就是lca了
#include <stdio.h>
#include <memory.h>

int tree[1010];
int visited[1010];
int color = 1;

int
main(void)
{
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t; ++ti)
    {
        int n;
        scanf("%d", &n);
        memset(1 + tree, 0, sizeof(int) * n);

        for(int i = 1; i <= n; ++i)
        {
            int m;
            scanf("%d", &m);

            while(m--)
            {
                int c;
                scanf("%d", &c);
                tree[c] = i;
            }
        }

        int q;
        printf("Case %d:\n", ti);
        scanf("%d", &q);
        while(q--)
        {
            int x, y, lca = 0;
            scanf("%d %d", &x, &y);

            while(x)
            {
                visited[x] = color;
                x = tree[x];
            }

            while(y)
            {
                if(visited[y] == color)
                {
                    lca = y;
                    break;
                }

                y = tree[y];
            }

            printf("%d\n", lca);

            ++color;
        }
    }

    return 0;
}
