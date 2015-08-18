// 开始想用筛法直接进行质因素分解的,但是因为上限是999999999999999,没有申请这么多内存
// 所以这里混合使用试除法和筛法.
// 1:用筛法生成sqrt(999999999999999) + 1内的素数,并记录合数的因式分解
// 2.读取一个数后通过add进行分解,因为结果的范围很大,但是实际数据量又不大,所以这儿用
//   map来记录结果,而不是数组.
//   在add中,如果i小于MAX,则直接将素数部分加入结果中,另外一部分进行递归处理
//   如果大于MAX,则使用试除法,从2到sqrt(i)尝试找到一个能被i整除的素数(这儿没优化),如果有则修改
//   该素数对应的结果,对剩余部分进行递归;如果没有,则说明i是素数,修改结果

// 这道题目用这种算法就可以了,评论里有说试除法的,但试除法本质上还是需要素数表
// 其他算法在求20位数的质因素分解时用
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

#define MAX 31622786
#define BIGINT long long int

struct node
{
    BIGINT prime;
    BIGINT rest;
};

map<BIGINT, BIGINT> result;
node array[MAX];

void
add(BIGINT i)
{
    if(i < MAX)
    {
        // 这里可以用循环实现,减少调用消耗
        if(array[i].prime)
        {
            ++result[array[i].prime];
            add(array[i].rest);
        }
        else
            ++result[i];
    }
    else
    {
        int sq = sqrt(i) + 1;
        int flag = 1;

        // 除了2,其他素数都是奇数,所以这儿可以将2单独提出
        // 然后后面每次取奇数判断即可,可以减少一半的访问
        for(int j = 2; j <= sq; ++j)
        {
            BIGINT ratio = array[j].prime;
            if(ratio)
                continue;

            if(i % j == 0)
            {
                ++result[j];
                flag = 0;
                add(i / j);
                break;
            }
        }

        if(flag)
            ++result[i];
    }
}

int
main(void)
{
    int sq = sqrt(MAX) + 1;
    for(int i = 2; i <= sq; ++i)
    {
        if(array[i].prime)
            continue;

        int z = 2;
        for(int j = i + i; j < MAX; j += i, ++z)
        {
            if(!array[j].prime)
            {
                array[j].prime = i;
                array[j].rest = z;
            }
        }
    }

    BIGINT n;
    while(true)
    {
        scanf("%lld", &n);
        if(!n)
            break;

        result.clear();
        add(n);
        map<BIGINT, BIGINT>::iterator iter = result.begin();
        while(iter != result.end())
        {
            printf("%lld^%lld ", iter->first, iter->second);
            ++iter;
        }
        printf("\n");
    }

    return 0;
}
