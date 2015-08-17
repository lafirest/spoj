// multiset的应用
#include <cstdio>
#include <set>
using namespace std;

multiset<int> prices;

int
main(void)
{
    int n;
    long long int cost = 0;
    scanf("%d", &n);
    while(n--)
    {
        int k;
        scanf("%d", &k);
        while(k--)
        {
            int v;
            scanf("%d", &v);
            prices.insert(v);
        }

        multiset<int>::iterator start = prices.begin();
        multiset<int>::iterator end = prices.end();
        // 注意这个,有可能集合为空
        if(start != end)
        {
            int small = *start;
            --end;
            int max = *end;

            // 集合有可能只有1个元素
            if(start == end)
            {
                cost += small;
                prices.erase(end);
            }
            else
            {
                cost += max - small;
                prices.erase(start);
                prices.erase(end);
            }
        }
    }

    printf("%lld\n", cost);
    return 0;
}
