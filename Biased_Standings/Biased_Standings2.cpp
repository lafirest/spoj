// 这是一个0(n)版本的实现,由上个版本可知,求的是排序后当前位置和需求位置的差值的和
// 因为涉及排序,所以复杂度是O(nlogn),如果不进行排序就可以大大提高效率,这儿是使用和
// 计数排序类似的算法.统计对某个位置的需求个数,然后从1开始,按照每个位置的需求进行填充(把值
// 像后排,可以想像成桶排序,只不过把桶里面存元素,改为了存元素个数),并计算需求位置和当前
// 填充位置直接的差值的和
#include <stdio.h>
#include <memory.h>

#define MAX 100001
int need[MAX];  // 版本1存的是rank序列,这里存的是需求序列
#define abs(x) ((x) > 0 ? (x) : -(x))

int
main(void)
{
    int t, n;
    char buff[255];
    scanf("%d", &t);
    while(t--)
    {
        long long bad = 0;
        scanf("%d", &n);
        memset(need + 1, 0, sizeof(int) * n); // 这儿开始漏掉了导致了3次wa
        for(int i = 1; i <= n; ++i)
        {
            int pos;
            scanf("%s %d", buff, &pos);
            ++need[pos];
        }
    
        for(int i = 1, pos = 1; i <= n; ++i)
        {
            int num = need[i]; 
            if(num != 0)
            {
                // 这里是一个等差数列来着,用等差数列的公式计算代替循环,对速度提升
                // 很有帮助,等差数列的公差可能是1或则-1,第一次提交时按照公差为1的来
                // 写的公式,第二次提交时公式对了,但还是ac(因为没有写memset),以为是
                // 公式写错了,然后就写成了这种直接循环求值的了
                for(int j = 1; j <= num; ++j)
                {
                    bad += abs(i - pos);
                    ++pos;
                }
            }
        }

        printf("%lld\n", bad);
    }
    return 0;
}


