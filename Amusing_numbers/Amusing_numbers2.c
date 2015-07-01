// 方案二是因为方案一里面用错了sqrt然后看网上的解,开始也想到了套用二进制,但是没发现规律
// 实际上方案一里面的偏移量就是方案二里面用来转换为二进制的部分
// 方案一里面通过log来求数据的大小,而方案二里面想将2的1~64次方都初始化,这样就可以不用log
// 函数了.求出数据的长度和相对偏移量后,将偏移量转换为二进制,而不足的位数补0(这里是5)
// 方案一中求长度和偏移量的算法和方案二本质上一样,但是求对应位置的数据则是通过偏移量在每位
// 中出现的位置来判断的,数学渣没法证明两个本质上是一样的
#include <stdio.h>
#include <math.h>

unsigned long long rang[64];
char bit[65];

int main(void)
{
    int i,n,l,p,l1;
    long long t;  

    rang[1] = 2;
    for(i = 2; i < 64; ++i)
        rang[i] = rang[i-1] * 2;

    scanf("%d", &n);
    while(n--)
    {
        scanf("%lld", &t);
        l = 0; 
        p = 0;
        l1 = 0;

        for(i = 51; i > 0; --i)
        {
            if(rang[i] < t + 2)
            {
                l = i;
                p = t - rang[i] + 1;
                break;
            }
        }

        for(l1 = 0; p;)
        {
            bit[l1] = (p % 2) + '5'; 
            p = p >> 1;
            ++l1;
        }

        for(i = 0; i < l - l1; ++i)
            putchar('5');

        for(i = l1 - 1; i >= 0; --i)
            putchar(bit[i]);

        printf("\n");
    }
    return 0;
}
