// 先找到这种序列的规律,然后判断输入的数据是否符合这种规律
#include <stdio.h>
#include <memory.h>
#define MAX 1001

short seq[MAX];

int read(void)
{
    int n = 0;

    char p = getchar();
    while(p < '0')
        p = getchar();

    while(p >= '0')
    {
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar();
    }

    return n;
}

int main(void)
{
    int t = read();
    while(t--)
    {
        int n = read();         
        for(int i = 1; i <= n; ++i)
            ++seq[read()];
        
        int mid = n >> 1;
        if(n & 1)
        {
            // 如果是n是奇数,那么序列最中间那个数不管是代表前面
            // 有多少,还是后面有多少,都是mid=(n - 1)/2,而且这个数
            // 只能出现一次,所以这里可以直接判断,快速过滤掉不能生成
            // 符合条件的序列的情况
            if(seq[mid] != 1)
                goto no;
        }

        // 序列从两头开始,对于每个i,其对应位置的值要么是n-i,要么是i-1
        // 对于头部,n-i代表后面有多少个数,i-1代表前面有多少个数
        // 对应尾部,n-i代表前面有多少个数,i-1代表后面有多少个数
        for(int i = 1, j = n; i <= mid; ++i, --j)
        {
            // 根据这个规律,按照统计的数据个数进行判断
            int i1 = i - 1;
            int i2 = n - i;
            if(seq[i1])
                --seq[i1];
            else if(seq[i2])
                --seq[i2];
            else 
                goto no;

            int j1 = j - 1;
            int j2 = n - j;
            if(seq[j1])
                --seq[j1];
            else if(seq[j2])
                --seq[j2];
            else 
                goto no;
        }

        puts("YES");
        goto end; // 其实YES时可以不用重置seq

no:
        puts("NO");
end: 
        for(int i = 1; i <= n; ++i)
            seq[i] = 0;
    }

    return 0;
}
