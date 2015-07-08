// 合并区间,思路是错的
#include <stdio.h>
#include <list>
using namespace std;

struct node
{
    int x;
    int y;
    int count;

    node(int i, int j, int k)
    {
        x = i;
        y = j;
        count = k;
    }
};

list<node> series;

int main(void)
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        int max = 1;
        series.clear();
        scanf("%d", &n);
        while(n--)
        {
            int i, j;
            scanf("%d %d", &i, &j);
            node p(i, j, 1);
            list<node>::iterator Iter = series.begin();
            while(Iter != series.end())
            {
                node& p = *Iter;

                ++Iter;
            }

            series.push_front(p);
        }

        printf("%d\n", max);
    }
}
