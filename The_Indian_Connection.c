// 看图找规律问题,开始已经找到规律了,但是代码实现有问题,看了githup上的一个代码才ac的
// 规律有两个:
// 1.对于某一代来说,整个序列是沿着中轴镜像对称的
// 2.序列的左半部分恰好是其上一代序列
// 所以解法就是:如果k在中轴的左边则直接去上一代找,如果在右边则映射到左边,并标记反转了方向
// 一直减到第二代就能找到答案了
// 进一步分析可以发现,这到题目其实和n没有关系,每次取log2(k),上取整n2,此时k就为n2的第k个元素了
// 然后k = k - n2/2,置一次反转,重复上述步骤,直到k为1,然后判断反转位即可
#include <stdio.h>
#include <math.h>

int calc(int n, long long int k)
{
    long long int v;
    if(n == 1)
        return 1;
    else if(n > 53)
        n = 53;

    int neg = 0;
    while(n > 2)
    {
        v = pow(2, n - 2);

        if(k > v)
        {
            k -= v;
            neg = !neg;
        }
        --n;
    }
    
    return (k % 2) ^ neg;
}

int main(void)
{
    int t,n;
    long long int k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %lld", &n, &k);
        if(calc(n, k))
            printf("Male\n");
        else
            printf("Female\n");
    }
    return 0;
}
