//素数筛法+因式分解问题.
//第一步:使用筛法来找出范围内的素数,并且存下合数的因式分解(不是质因数)
//第二步:遍历范围内所有的数,如果是素数则直接将结果加1,如果是合数,则通过
//       记录下来的合数的因式分解进行dfs,一直到将合数分解到质因素为止
//第三步:遍历结果数组,打印输出

//补充:这里可以优化下:
//1.去掉factor数组,在array中素数的值为0,合数(c)的值为高16为a,低16位b, c = a * b
//2.将c的因数中的素数始终放在高位,则在执行add操作时,就不需要对高位进行判断,减少一次分支预测
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <list>
using namespace std;

#define MAX 10010
int array[MAX];
int result[MAX];
list<int> factor[MAX];

void
add(int i)
{
    list<int>& il = factor[i];
    list<int>::iterator iter = il.begin();
    while(iter != il.end())
    {   
        int temp = *iter;
        if(array[temp])
            add(temp);
        else
            ++result[temp];
        
        ++iter;
    }
}

int
main(void)
{
    int n;
    scanf("%d", &n);

    // 筛选素数,记录合数的因式分解
    int sq = sqrt(n) + 1;
    for(int i = 2; i <= sq; ++i)
    {
        if(array[i])
            continue;

        int z = 2;
        for(int j = i + i; j <= n; j += i, ++z)
        {
            array[j] = 1;
            list<int>& jl = factor[j];
            if(jl.empty())
            {
                jl.push_front(i);
                jl.push_front(z);
            }
        }
    }

    // 对阶乘中的每个数进行递归分解
    for(int i = 2; i <= n; ++i)
    {
        if(array[i])
            add(i);
        else
            ++result[i];
    }

    int flag = 0;
    for(int i = 2; i <= n; ++i)
    {
        if(result[i])
        {
            if(flag)
                printf(" * ");
            printf("%d^%d", i, result[i]);
            flag = 1;
        }
    }

    printf("\n");

    return 0;
}
