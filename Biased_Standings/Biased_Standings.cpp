// 版本1 时间复杂度:O(nlogn + n), ac
// 版本2 时间复杂度:O(n), ac 
// 这个算是一个贪心问题吧,对输入从小到大排序,然后计算当前实际位置和需求位置的差值和
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 100001
long long int rank[MAX];
#define abs(x) ((x) > 0 ? (x) : -(x))

int
main(void)
{
    int t, n;
    char buff[255];
    scanf("%d", &t);
    while(t--)
    {
        long long int bad = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%s %lld", buff, &rank[i]);
    
        sort(rank + 1, rank + n + 1);

        for(int i = 1; i <= n; ++i)
            bad += abs(rank[i] - i);

        printf("%lld\n", bad);
    }
    return 0;
}


