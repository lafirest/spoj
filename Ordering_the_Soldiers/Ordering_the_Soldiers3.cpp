// 前一个算法tle了,能进行改进的就是最后的sort了,这里就是将sort改为了计数排序
// 得到了按照值排好序后的位置顺序,其实就得到了原理位置到值的映射关系,然后直接
// 用计数排序就可以了 
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 200010

int pos[MAX];
int value[MAX];

int
main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;     
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
        {
            int tmp;
            int j = i;
            scanf("%d", &tmp);

            if(tmp)
            {
                for( ; j > i - tmp; --j)
                {
                    pos[j]= pos[j-1];
                }
            }

            pos[j] = i;
        }

        for(int i = 1; i <= n; ++i)
            value[pos[i]] = i;

        for(int i = 1; i < n; ++i)
            printf("%d ", value[i]);

        printf("%d\n", value[n]);
    }

    return 0;
}
