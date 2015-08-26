// tle
// 进行了简单的数学分析,然后得出了现在的这种方案:
// 1.输入是按照顺序来的,即第一个数据是在第一个位置上
// 2.记录每个位置,然后按照输入进行位置交换.输入为0,则
//   元素不移动,输入为1,则和前1个元素交换,为2则移动到2个位置前...
// 3.最后得到的是按照值排好序后的位置顺序,因为值已经排好序了,
//   所以第一个位置对应的值是1,下一个对应的是2...
// 4.将位置按照升序排序,输入对应的值
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 200010

struct node 
{
    int pos;
    int value;

    bool operator < (const node& that)
    {
        return pos < that.pos;
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
        for(int i = 1; i <= n; ++i)
        {
            int tmp;
            int j = i;
            scanf("%d", &tmp);

            if(tmp)
            {
                for( ; j > i - tmp; --j)
                {
                    array[j].pos = array[j-1].pos;
                }
            }

            array[j].pos = i;
        }

        for(int i = 1; i <= n; ++i)
            array[i].value = i;

        sort(array + 1, array + n + 1);

        for(int i = 1; i < n; ++i)
            printf("%d ", array[i].value);

        printf("%d\n", array[n].value);
    }

    return 0;
}
