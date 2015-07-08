// 这个思路是看githup上得到的,还有种使用优先队列的,没有这个简洁.这个
// 问题我最先想到的是区间树,然后答案实际上就是区间树的最大交集个数,
// 但是区间树实现复杂,于是我就尝试了其他方法,都没有AC.
// 这个方案的思路很简单,对进入时间和离开时间分别排序,某个时间段有人进来
// 则人数加1,有人离开则减1，哪个时间段人最多,就是解了
#include <stdio.h>
#include <algorithm>
using namespace std;

int in[10000001];
int out[10000001];

int main(void)
{
    int t, n; 
    scanf("%d", &t);
    while(t--)
    {
        int max = 0;
        int pos = 0;

        scanf("%d", &n);
        while(n--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            in[pos] = x;
            out[pos] = y;
            ++pos;
        }

        sort(in, in + pos);
        sort(out, out + pos);

        int i = 0, j = 0, num = 0;
        while(i < pos)
        {
            if(in[i] < out[j])
            {
                ++num;
                ++i;
                if(num > max)
                    max = num;
            }
            else
            {
                --num;
                ++j;
            }
        }

        printf("%d\n", max);
    }
}
