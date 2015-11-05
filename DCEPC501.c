// 开始一直在想有没有非递归的实现方案...后面实在没有想出来,
// 而且网上能找到的代码都是递归实现的
// 这里就是用递归+记忆化.如果不记忆化的话,会tle,还有就是值
// 需要用64位数来存,否则会溢出
#include <stdio.h>
#include <memory.h>

#define MAX 100010
#define bigint long long int
int array[MAX];
bigint memory[MAX];

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

bigint calc(int s, int e)
{
    bigint r = 0;
    if(s <= e)
    {
        if(memory[s] != -1)
            r = memory[s];
        else if(e - s <= 2)
        {
            for(int i = s; i <= e; ++i)
                r += array[i];

            memory[s] = r;
        }
        else
        {
            bigint x = array[s] + calc(s + 2, e);
            bigint y = 0;
            bigint z = 0;
            if(s + 1 <= e)
                y = array[s] + array[s+1] + calc(s + 4, e);
            if(s + 2 <= e)
                z = array[s] + array[s+1] + array[s+2] + calc(s + 6, e);

            if(x > y)
            {
                if(x > z)
                    r = x;
                else 
                    r = z;
            }
            else 
            {
                if(y > z)
                    r = y;
                else 
                    r = z;
            }

            memory[s] = r;
        }
    }

    return r;
}

int main(void)
{
    int t = read();

    while(t--)
    {
        int n = read();
        for(int i = 0; i < n; ++i)
            array[i] = read();            

        memset(memory, -1, sizeof(bigint) * n); // 将sizeof(memory)改为这样写速度提升了0.01s
        printf("%lld\n", calc(0, n - 1));
    }

    return 0;
}
