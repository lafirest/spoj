// 这道题目的方法是错的,在于没有想清楚就胡乱写代码
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 200010

struct node 
{
    int weight;
    int pos;

    bool operator < (const node& that)
    {
        if(weight == that.weight)
            return pos > that.pos;
        else
            return weight > that.weight;
    }
};

node array[MAX];

int
main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;     
        scanf("%d", &n);
        for(int i = 1, j = MAX; i <= n; ++i, --j)
        {
            int tmp;
            scanf("%d", &tmp);
            array[i].pos = i;
            array[i].weight = j + tmp;
        }

        sort(array + 1, array + n + 1);

        for(int i = 1; i < n; ++i)
            printf("%d ", array[i].pos);

        printf("%d\n", array[n].pos);
    }
    return 0;
}
